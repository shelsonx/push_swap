/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:09:57 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/28 17:15:42 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_nodes(t_node **lst)
{
	t_node	*next;

	if (!lst)
		return ;
	next = *lst;
	while (next)
	{
		next = next->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

void	free_stacks(t_data *data)
{
	ft_free_nodes(&data->stack_a->list);
	free(data->stack_a);
	if (data->stack_b != NULL)
	{
		ft_free_nodes(&data->stack_b->list);
		free(data->stack_b);
	}
}
