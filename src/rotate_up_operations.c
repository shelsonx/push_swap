/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_up_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:07:52 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/15 16:01:48 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	int		head_value;
	int		head_index;
	t_node	*tmp;

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
	ft_printf("ra\n");
}

void	rotate_b(t_stack *stack_b)
{
	if (stack_b == NULL)
		return ;
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_all(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a != NULL)
		rotate(stack_a);
	if (stack_b != NULL)
		rotate(stack_b);
	if (stack_a != NULL || stack_b != NULL)
		ft_printf("rr\n");
}
