/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:07:52 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/23 23:59:00 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*last;
	int		size;

	if (ft_size(stack->list) < 2)
		return ;
	size = ft_size(stack->list);
	current = stack->list;
	while (--size > 1)
		current = current->next;
	last = ft_last(stack->list);
	last->next = stack->list;
	stack->list = last;
	current->next = NULL;
}

void	reverse_rotate_a(t_stack *stack_a)
{
	if (stack_a == NULL)
		return ;
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void	reverse_rotate_b(t_stack *stack_b)
{
	if (stack_b == NULL)
		return ;
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", STDOUT_FILENO);
}

void	reverse_rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a != NULL)
		reverse_rotate(stack_a);
	if (stack_a != NULL)
		reverse_rotate(stack_b);
	if (stack_a != NULL || stack_b != NULL)
		ft_putendl_fd("rrr", STDOUT_FILENO);
}
