/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:28:23 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/20 22:07:22 by sjhony-x         ###   ########.fr       */
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

static int	contains_duplicate(t_node *list)
{
	int size;
	int	*arr;
	int	i;

	size = ft_size(list);
	arr = malloc(sizeof(int *) * size);
	if (arr == NULL)
		return (-1);
	fill_array(list, arr, size);
	quick_sort(arr, 0, size -1);
	i = 0;
	while (i < (size -1))
	{
		if (arr[i] == arr[i +1])
		{	
			free(arr);
			return (TRUE);
		}
		i++;
	}
	free(arr);
	return (FALSE);
}

int	validate(t_data *data)
{
	t_node	*list;

	list = data->stack_a->list; 
	if (is_sorted(list) || contains_duplicate(list))
		return (FALSE);
	return (TRUE);
}
