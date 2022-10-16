/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:34 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/15 23:43:39 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data)
{
	t_node	*node;

	node = data->stack_a->list;
	if (node->value > node->next->value)
		swap_sa(data);
}

void	sort_three(t_data *data)
{
	t_node	*list;

	list = data->stack_a->list;
	if (list->value > list->next->value && list->next->value
		< list->next->next->value && list->next->next->value > list->value)
		swap_sa(data);
	else if (list->value > list->next->value
		&& list->next->value > list->next->next->value)
	{
		swap_sa(data);
		reverse_rotate_a(data->stack_a);
	}
	else if (list->value > list->next->value && list->next->value
		< list->next->next->value && list->next->next->value < list->value)
		rotate_a(data->stack_a);
	else if (list->value < list->next->value && list->next->value
		> list->next->next->value && list->next->next->value > list->value)
	{
		swap_sa(data);
		rotate_a(data->stack_a);
	}
	else if (list->value < list->next->value && list->next->value
		> list->next->next->value && list->next->next->value < list->value)
		reverse_rotate_a(data->stack_a);
}
