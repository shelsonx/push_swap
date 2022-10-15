/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:36:45 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/15 06:10:49 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(t_data *data)
{
	int	i;

	data->stack_a = malloc(sizeof(t_stack));
	if (data->stack_a == NULL)
		return ;
	data->stack_a->list = NULL;
	i = 0;
	while (++i < data->argc)
		ft_add_back(&data->stack_a->list,
			ft_new(ft_atoi(data->argv[i])));
	data->stack_a->size = ft_size(data->stack_a->list);
	data->stack_b = NULL;
}

void	set_index(t_node *list, int size, int index)
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

void	init_stack_b(t_data *data)
{
	data->stack_b = malloc(sizeof(t_stack));
	if (data->stack_b == NULL)
		return ;
	data->stack_b->list = NULL;
}

void	init(int argc, char **argv, t_data *data)
{
	data->argc = argc;
	data->argv = argv;
	init_stacks(data);
}
