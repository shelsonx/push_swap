/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:32:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/18 18:49:34 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_smallests_to_b(t_data *data)
{
	int		mid;
	int		size;

	size = ft_size(data->stack_a->list);
	mid = size / 2;
	while (--size >= 3)
	{
		if (data->stack_a->list->index < mid)
			push_b(data);
		else
			rotate_a(data->stack_a);
	}
	size = ft_size(data->stack_a->list);
	while (--size >= 3)
		push_b(data);
}

int	abs(int value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

int	get_total_cost(t_node *node)
{
	return (abs(node->cost_a) + abs(node->cost_b));
}

t_node	*get_cheaper(t_node *list)
{
	t_node	*current;
	t_node	*cheaper;

	current = list;
	cheaper = list;
	while (current)
	{
		if (get_total_cost(current) < get_total_cost(cheaper))
			cheaper = current;
		current = current->next;
	}
	return (cheaper);
}

void	rotate_stacks(t_data *data, t_node *node_cheaper)
{
	while (node_cheaper->cost_a > 0 && node_cheaper->cost_b > 0)
	{
		rotate_all(data->stack_a, data->stack_b);
		node_cheaper->cost_a--;
		node_cheaper->cost_b--;
	}
	while (node_cheaper->cost_a < 0 && node_cheaper->cost_b < 0)
	{
		reverse_rotate_all(data->stack_a, data->stack_b);
		node_cheaper->cost_a++;
		node_cheaper->cost_b++;
	}
}

void	rotate_stack(int *cost, t_stack *stack, 
		void(*r)(t_stack *), void(*rr)(t_stack *))
{
	while (*cost)
	{
		if (*cost > 0)
		{
			r(stack);
			(*cost)--;
		}
		else
		{
			rr(stack);
			(*cost)++;
		}
	}
}

void	run_actions(t_data *data, t_node *node_cheaper)
{
	rotate_stacks(data, node_cheaper);
	rotate_stack(&node_cheaper->cost_a, data->stack_a, rotate_a, reverse_rotate_a);
	rotate_stack(&node_cheaper->cost_b, data->stack_b, rotate_b, reverse_rotate_b);
}

void	sort_large(t_data *data)
{
	t_node	*node_cheaper;
	int		size;

	put_smallests_to_b(data);
	sort_three(data);
	size = ft_size(data->stack_b->list);
	while (size--)
	{
		set_positions(data->stack_a->list);
		set_positions(data->stack_b->list);
		set_targets_pos(data->stack_a, data->stack_b);
		set_costs(data);
		node_cheaper = get_cheaper(data->stack_b->list);
		run_actions(data, node_cheaper);
		push_a(data);
	}
}
