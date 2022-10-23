/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:07:52 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/23 23:59:29 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	int		head_value;
	int		head_index;
	t_node	*tmp;

	if (ft_size(stack->list) < 2)
		return ;
	head_value = stack->list->value;
	head_index = stack->list->index;
	tmp = stack->list;
	stack->list = stack->list->next;
	free(tmp);
	ft_add_back(&stack->list,
		ft_new(head_value, head_index));
}

void	rotate_a(t_stack *stack_a)
{
	if (stack_a == NULL)
		return ;
	rotate(stack_a);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	rotate_b(t_stack *stack_b)
{
	if (stack_b == NULL)
		return ;
	rotate(stack_b);
	ft_putendl_fd("rb", STDOUT_FILENO);
}

void	rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a != NULL)
		rotate(stack_a);
	if (stack_b != NULL)
		rotate(stack_b);
	if (stack_a != NULL || stack_b != NULL)
		ft_putendl_fd("rr", STDOUT_FILENO);
}
