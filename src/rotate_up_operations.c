/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:07:52 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/28 01:17:29 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack  *stack_a)
{
	int		head_value;
	t_node	*tmp;

	if (stack_a == NULL)
		return ;
	head_value = stack_a->list->value;
	tmp = stack_a->list; 
	stack_a->list = stack_a->list->next;
	free(tmp);
	ft_add_back(&stack_a->list, 
		ft_new(head_value));
}

