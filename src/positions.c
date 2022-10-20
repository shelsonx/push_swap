/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:42:36 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/20 14:49:30 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target(t_stack *stack, t_node *element)
{
	t_node	*current;
	int		biggest;

	biggest = find_biggest_index(stack->list);
	current = stack->list;
	while (current)
	{
		if (element->index < current->index && current->index <= biggest)
		{
			element->target_pos = current->position;
			biggest = current->index;
		}
		current = current->next;
	}
	if (element->index > biggest)
		element->target_pos = find_smallest_position(stack->list);
}

void	set_targets_pos(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;

	current = stack_b->list;
	while (current)
	{
		set_target(stack_a, current);
		current = current->next;
	}
}

static void	set_index(t_node *list, int size, int index)
{
	t_node	*current;
	int		i;

	i = -1;
	current = list;
	while (++i < size)
		current = current->next;
	current->index = index;
}

void	set_indexes(t_node *list)
{
	int	size;
	int	i;
	int	*arr;

	size = ft_size(list);
	arr = malloc(sizeof(int *) * size);
	fill_array(list, arr, size);
	quick_sort(arr, 0, size - 1);
	i = -1;
	while (++i < size)
		set_index(list, find_index(list, arr[i]), i +1);
	free(arr);
}

void	set_positions(t_node *list)
{
	t_node	*current;
	int		i;

	i = 0;
	current = list;
	while (current)
	{
		current->position = i;
		i++;
		current = current->next;
	}
}
