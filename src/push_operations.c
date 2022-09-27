/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:13:32 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/28 00:02:55 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_data *data)
{
	t_node	*tmp;

	if (data->stack_a->list == NULL)
		return ;
	if (data->stack_b == NULL)
		init_stack_b(data);
	ft_add_front(&data->stack_b->list,
		ft_new(data->stack_a->list->value));
	data->stack_b->size = ft_size(data->stack_b->list);
	tmp = data->stack_a->list->next;
	free(data->stack_a->list);
	data->stack_a->list = tmp;
}
