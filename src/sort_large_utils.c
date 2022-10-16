/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:42:36 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/16 07:45:50 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_mid_value(t_data *data)
{
	int	*arr;

	data->stack_a->size = ft_size(data->stack_a->list);
	arr = malloc(sizeof(int *) * data->stack_a->size);
	fill_array(data->stack_a->list, arr, data->stack_a->size);
	quick_sort(arr, 0, data->stack_a->size - 1);
	data->stack_a->mid = arr[data->stack_a->size / 2];
	free(arr);
}

void	push_after_mid(t_data *data)
{
	t_node	*last;

	last = ft_last(data->stack_a->list);
	while (last->value < data->stack_a->mid)
	{
		reverse_rotate_a(data->stack_a);
		push_b(data);
		last = ft_last(data->stack_a->list);
	}
}

void	push_before_mid(t_data *data)
{
	while (data->stack_a->list->value < data->stack_a->mid)
		push_b(data);
}

void	skip_bigger_mid(t_data *data)
{	
	while (data->stack_a->list->value > data->stack_a->mid)
		rotate_a(data->stack_a);
}

void	skip_equals_mid(t_data *data)
{
	if (data->stack_a->list->value == data->stack_a->mid)
		rotate_a(data->stack_a);
}

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
