/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:32:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/07 14:51:22 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_data(t_data *data)
{
	int	*arr;

	data->stack_a->size = ft_size(data->stack_a->list);
	arr = malloc(sizeof(int *) * data->stack_a->size);
	fill_array(data->stack_a->list, arr, data->stack_a->size);
	quick_sort(arr, 0, data->stack_a->size - 1);
	data->stack_a->mid = arr[data->stack_a->size / 2];
}

void	put_smallests_to_b(t_data *data)
{
	set_data(data);
	while (data->stack_a->list->value < data->stack_a->mid)
		push_b(data);
}

void	sort_large(t_data *data)
{
	put_smallests_to_b(data);
}
