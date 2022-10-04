/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:34 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/28 17:14:15 by sjhony-x         ###   ########.fr       */
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
	else if(list->value < list->next->value && list->next->value
		> list->next->next->value && list->next->next->value < list->value)
		reverse_rotate_a(data->stack_a);
}

void	sort_four(t_data *data)
{
	int	smallest;

	smallest = find_smallest_index(data->stack_a->list);
	if (smallest == 1)
		rotate_a(data->stack_a);
	else if (smallest == 2)
	{
		reverse_rotate_a(data->stack_a);
		reverse_rotate_a(data->stack_a);
	}
	else if (smallest == 3)
		reverse_rotate_a(data->stack_a);
	push_b(data);
	sort_three(data);
	push_a(data);
}

void	sort_five(t_data *data)
{
	int	smallest;

	smallest = find_smallest_index(data->stack_a->list);
	if (smallest == 1)
		rotate_a(data->stack_a);
	else if (smallest == 2)
	{
		reverse_rotate_a(data->stack_a);
		reverse_rotate_a(data->stack_a);
		reverse_rotate_a(data->stack_a);
	}
	else if (smallest == 3)
	{
		rotate_a(data->stack_a);
		rotate_a(data->stack_a);
		rotate_a(data->stack_a);
	}
	else if (smallest == 4)
		reverse_rotate_a(data->stack_a);
	push_b(data);
	sort_four(data);
	push_a(data);
}
