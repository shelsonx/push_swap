/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:07:52 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/18 19:12:56 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*tail;
	int		size;

	size = ft_size(stack->list);
	current = stack->list;
	while (--size > 1)
		current = current->next;
	tail = current->next;
	current->next = NULL;
	ft_add_front(&stack->list,
		ft_new(tail->value, tail->index));
	free(tail);
}

void	reverse_rotate_a(t_stack *stack_a)
{
	if (stack_a == NULL)
		return ;
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack *stack_b)
{
	if (stack_b == NULL)
		return ;
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	reverse_rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a != NULL)
		reverse_rotate(stack_a);
	if (stack_a != NULL)
		reverse_rotate(stack_b);
	if (stack_a != NULL || stack_b != NULL)
		ft_printf("rrr\n");
}
