/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:34:27 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/28 17:17:19 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_node *list)
{
	int	tmp;

	tmp = list->value;
	list->value = list->next->value;
	list->next->value = tmp;
}

void	swap_sa(t_data *data)
{
	if (data->stack_a == NULL)
		return ;
	swap(data->stack_a->list);
	ft_printf("sa\n");
}

void	swap_sb(t_data *data)
{
	if (data->stack_b == NULL)
		return ;
	swap(data->stack_b->list);
	ft_printf("sb\n");
}

void	swap_ss(t_data *data)
{
	if (data->stack_a != NULL)
		swap(data->stack_a->list);
	if (data->stack_b != NULL)
		swap(data->stack_b->list);
	if (data->stack_a != NULL || data->stack_a != NULL) 
		ft_printf("ss\n");
}
