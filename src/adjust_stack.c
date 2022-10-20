/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:56:37 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/20 14:47:35 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adjust_last_element(t_stack *stack_a)
{
	t_node	*last;
	int		size;
	int		biggest_position;

	set_positions(stack_a->list);
	last = ft_last(stack_a->list);
	size = ft_size(stack_a->list);
	biggest_position = find_biggest_position(stack_a->list);
	while (last->index != size)
	{
		if (biggest_position < (size / 2))
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
		last = ft_last(stack_a->list);
	}
}

static void	adjust_first_element(t_stack *stack_a)
{
	int		size;
	int		smallest_position;

	set_positions(stack_a->list);
	size = ft_size(stack_a->list);
	smallest_position = find_smallest_position(stack_a->list);
	while (stack_a->list->index != 1)
	{
		if (smallest_position < size / 2)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
	set_positions(stack_a->list);
}

void	adjust_stack_a(t_stack *stack_a)
{
	adjust_first_element(stack_a);
	adjust_last_element(stack_a);
}
