/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:32:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/20 05:40:13 by sjhony-x         ###   ########.fr       */
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
