/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:42:36 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/17 13:13:59 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_pos(t_stack *stack, int index)
{
	t_node	*current;

	current = stack->list;
	while (current->next)
	{
		if (current->index < index && index < current->next->index)
			return current->next->position;
		current = current->next;	
	}
	if (current->next == NULL)
		return (find_smallest_position(stack->list));
	return (-1);
}

void	set_targets_pos(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;

	current = stack_b->list;
	while (current)
	{
		current->target_pos = get_target_pos(stack_a, current->index);;
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
