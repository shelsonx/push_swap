/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:28:23 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/06 07:54:43 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *list)
{
	t_node	*current;

	current = list;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

int	contains_duplicate(int *arr, int size)
{
	int	i;

	quick_sort(arr, 0, size -1);
	i = 0;
	while (i < (size -1))
	{
		if (arr[i] == arr[i +1])
			return (TRUE);
		i++;
	}
	return (FALSE);
}
