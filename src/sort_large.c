/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:32:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/07 20:07:53 by sjhony-x         ###   ########.fr       */
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

void	push_before_mid(t_data *data)
{
	while (data->stack_a->list->value < data->stack_a->mid)
		push_b(data);
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

void	put_smallests_to_b(t_data *data)
{
	while (ft_size(data->stack_a->list) > 2)
	{
		set_mid_value(data);
		push_before_mid(data);
		push_after_mid(data);
		skip_bigger_mid(data);
		push_before_mid(data);
		skip_bigger_mid(data);
		skip_equals_mid(data);
		push_before_mid(data);
	}
	sort_two(data);
}

void	sort_large(t_data *data)
{
	put_smallests_to_b(data);
}
