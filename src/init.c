/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:36:45 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/18 02:29:36 by sjhony-x         ###   ########.fr       */
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
			ft_new(ft_atoi(data->argv[i]), -1));
	data->stack_a->size = ft_size(data->stack_a->list);
	data->stack_b = NULL;
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
	set_indexes(data->stack_a->list);
	set_positions(data->stack_a->list);
}
