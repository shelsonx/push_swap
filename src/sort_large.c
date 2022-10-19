/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:32:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/19 01:58:38 by sjhony-x         ###   ########.fr       */
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
	while (current->next)
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
	t_node	*last;
	int		size;
	int		biggest_index;

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
	set_positions(data->stack_a->list);
	last = ft_last(data->stack_a->list);
	size = ft_size(data->stack_a->list);
	
	biggest_index = find_biggest_position(data->stack_a->list);
	while (last->index != size)
	{
		if (biggest_index < (size / 2))
			rotate_a(data->stack_a);
		else
			reverse_rotate_a(data->stack_a);
		last = ft_last(data->stack_a->list);
	}
	set_positions(data->stack_a->list);
	while (data->stack_a->list->index != 1)
	{
		if (biggest_index < size / 2)
			rotate_a(data->stack_a);
		else
			reverse_rotate_a(data->stack_a);
	}
	set_positions(data->stack_a->list);
	if (is_sorted(data->stack_a->list))
		ft_printf("Yes!\n");
	else
		ft_printf("No!\n");
}
