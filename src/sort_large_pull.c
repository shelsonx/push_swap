/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_pull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:42:36 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/09 16:15:06 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_mid_value_stack_b(t_data *data)
{
	int	*arr;

	arr = malloc(sizeof(int *) * data->stack_b->size);
	fill_array(data->stack_b->list, arr, data->stack_b->size);
	quick_sort(arr, 0, data->stack_b->size - 1);
	data->stack_b->mid = arr[data->stack_b->size / 2];
	free(arr);
}

void	pull_after_mid(t_data *data)
{
	t_node		*last;

	last = ft_last(data->stack_b->list);
	while (last->value > data->stack_b->mid)
	{
		reverse_rotate_b(data->stack_b);
		push_a(data);
		last = ft_last(data->stack_b->list);
	}
}

void	pull_before_mid(t_data *data)
{
	while (data->stack_b->list->value > data->stack_b->mid)
		push_a(data);
}

void	skip_smallest_mid(t_data *data)
{
	while (data->stack_b->list->value < data->stack_b->mid)
		rotate_b(data->stack_b);
}

void	skip_equals_mid_stack_b(t_data *data)
{
	if (data->stack_b->list->value == data->stack_b->mid)
		rotate_b(data->stack_b);
}
