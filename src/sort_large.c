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

void	adjust_last_element(t_stack *stack_a)
{
	t_node	*last;
	int		size;
	int		biggest_position;

	set_positions(stack_a->list);
	last = ft_last(stack_a->list);
	size = ft_size(stack_a->list);
	biggest_position = find_biggest_position(stack_a->list);
	while (last->index != size)
	{
		if (biggest_position < (size / 2))
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
		last = ft_last(stack_a->list);
	}
}

void	adjust_first_element(t_stack *stack_a)
{
	int		size;
	int		smallest_position;

	set_positions(stack_a->list);
	size = ft_size(stack_a->list);
	smallest_position = find_smallest_position(stack_a->list);
	while (stack_a->list->index != 1)
	{
		if (smallest_position < size / 2)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
	set_positions(stack_a->list);
}

void	adjust_stack_a(t_stack *stack_a)
{
	adjust_first_element(stack_a);
	adjust_last_element(stack_a);
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
	if (!is_sorted(data->stack_a->list))
		adjust_stack_a(data->stack_a);
}
