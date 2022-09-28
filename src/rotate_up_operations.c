/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:07:52 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/28 17:20:37 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	int		head_value;
	t_node	*tmp;

	if (stack == NULL)
		return ;
	head_value = stack->list->value;
	tmp = stack->list;
	stack->list = stack->list->next;
	free(tmp);
	ft_add_back(&stack->list,
		ft_new(head_value));
}

void	rotate_a(t_stack *stack_a)
{
	rotate(stack_a);
}

void	rotate_b(t_stack *stack_b)
{
	rotate(stack_b);
}

void	rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
