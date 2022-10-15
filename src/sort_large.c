/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:32:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/15 06:06:48 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	steps_to_push_smallests(t_data *data)
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

void	steps_to_pull_smallests(t_data *data)
{
	set_mid_value_stack_b(data);
	pull_before_mid(data);
	//pull_after_mid(data);
	skip_equals_mid_stack_b(data);
	skip_smallest_mid(data);
	pull_before_mid(data);
	skip_smallest_mid(data);
	//skip_equals_mid_stack_b(data);
	pull_before_mid(data);
	if (data->stack_b->list->value == data->stack_b->mid
		&& data->stack_b->list->value > data->stack_b->list->next->value)
		push_a(data);
		
}


void	put_smallests_to_b(t_data *data)
{
	if (ft_size(data->stack_a->list) == 2)
	{
		sort_two(data);
		return ;
	}
	steps_to_push_smallests(data);
	put_smallests_to_b(data);
}

void	put_biggets_to_a(t_data *data)
{
	int biggest;
	int	size;
	int	mid;
	int	index_biggest;

	while (ft_size(data->stack_b->list) > 0)
	{
		biggest = find_biggest(data->stack_b->list);
		size = ft_size(data->stack_b->list);
		mid = size / 2;
		index_biggest = find_index(data->stack_b->list, biggest);

		while (data->stack_b->list->value < biggest)
		{
			if (index_biggest > mid)
				reverse_rotate_b(data->stack_b);
			else
				rotate_b(data->stack_b);
		}
		push_a(data);
	}
}

void	sort_large(t_data *data)
{
	set_indexes(data->stack_a->list);
	//put_smallests_to_b(data);
	//put_biggets_to_a(data);
}
