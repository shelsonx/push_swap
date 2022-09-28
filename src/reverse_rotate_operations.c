/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:07:52 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/28 02:52:14 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack  *stack)
{
	int		tail_value;
	t_node	*current;
	t_node	*tail;
	int		size;

	if (stack == NULL)
		return ;
	tail = ft_last(stack->list);
	tail_value = tail->value;
	
	size = ft_size(stack->list);
	current = stack->list;
	while (size > 2)
	{
		current = current->next;
		size--;
	}
	free(tail);
	current->next = NULL;
	ft_add_front(&stack->list, 
		ft_new(tail_value));
}

/* void	rotate_a(t_stack  *stack_a)
{
	rotate(stack_a);
}

void	rotate_b(t_stack  *stack_b)
{
	rotate(stack_b);
}

void	rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
} */
