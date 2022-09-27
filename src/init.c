/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:36:45 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/27 06:03:12 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(int argc, char **argv, t_data *data)
{
	int	i;
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	stack->head = NULL;

	data->argc = argc;
	data->argv = argv;
	data->stack_a = stack;
	i = 0;
	while (++i < data->argc)
		ft_add_back(&data->stack_a->head, 
			ft_new(ft_atoi(data->argv[i])));
	data->stack_a->size = ft_size(data->stack_a->head);
	data->stack_b = NULL;
}
