/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:43:03 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/14 08:47:13 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_index(t_node *list)
{
	t_node	*current;
	int		smallest;
	int		smallest_index;
	int		index;

	current = list;
	smallest = list->value;
	index = 0;
	smallest_index = 0;
	while (current != NULL)
	{
		if (current->value < smallest)
		{
			smallest = current->value;
			smallest_index = index;
		}
		current = current->next;
		index++;
	}
	return (smallest_index);
}

int	find_biggest(t_node *list)
{
	t_node	*current;
	int		biggest;

	current = list;
	biggest = list->value;
	while (current != NULL)
	{
		if (current->value > biggest)
			biggest = current->value;
		current = current->next;
	}
	return (biggest);
}

int	find_index(t_node *list, int value)
{
	t_node	*current;
	int		index;

	current = list;
	index = 0;
	while (current)
	{
		if (current->value == value)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

void	fill_array(t_node *list, int *arr, int size)
{
	t_node	*current;
	int		i;

	current = list;
	i = 0;
	while (i < size)
	{
		arr[i] = current->value;
		i++;
		current = current->next;
	}
}
