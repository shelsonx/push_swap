/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:42:36 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/19 01:56:56 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_stack *stack, t_node *element)
{
	t_node	*current;
	int biggest;

	biggest = find_biggest_index(stack->list);
	current = stack->list;
	while (current)
	{
		if (element->index < current->index && current->index <= biggest)
		{
			element->target_pos = current->position;
			biggest = current->index;
		}
		current = current->next;
	}
	if (element->index > biggest)
		element->target_pos = find_smallest_position(stack->list);
}

void	set_targets_pos(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;

	current = stack_b->list;
	while (current)
	{
		set_target(stack_a, current);
		current = current->next;
	}
}

int	get_cost(int position, int size)
{
	int mid;

	mid =  size / 2;
	if (position > mid)
		return (position - size);
	return (position);
}

void	set_costs(t_data *data)
{
	int size_a;
	int size_b;
	t_node *current;

	size_a = ft_size(data->stack_a->list);
	size_b = ft_size(data->stack_b->list);
	current = data->stack_b->list;
	while (current)
	{
		current->cost_a = get_cost(current->target_pos, size_a);
		current->cost_b = get_cost(current->position, size_b);
		current = current->next;
	}
}
