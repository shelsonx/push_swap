/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:07:52 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/28 17:18:44 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*tail;
	int		size;

	if (stack == NULL)
		return ;
	size = ft_size(stack->list);
	current = stack->list;
	while (--size > 1)
		current = current->next;
	tail = current->next;
	current->next = NULL;
	ft_add_front(&stack->list,
		ft_new(tail->value));
	free(tail);
}

void	reverse_rotate_a(t_stack *stack_a)
{
	reverse_rotate(stack_a);
}

void	reverse_rotate_b(t_stack *stack_b)
{
	reverse_rotate(stack_b);
}

void	reverse_rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
