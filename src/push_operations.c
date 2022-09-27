/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:13:32 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/28 00:48:42 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *first, t_stack *second)
{
	t_node	*tmp;

	ft_add_front(&second->list,
		ft_new(first->list->value));
	tmp = first->list->next;
	free(first->list);
	first->list = tmp;
}

void	push_b(t_data *data)
{
	if (data->stack_a->list == NULL)
		return ;
	if (data->stack_b == NULL)
		init_stack_b(data);
	push(data->stack_a, data->stack_b);
}

void	push_a(t_data *data)
{
	if (data->stack_b->list == NULL)
		return ;
	push(data->stack_b, data->stack_a);
}