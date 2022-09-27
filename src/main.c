/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:25:30 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/27 17:11:49 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *current;
	t_data data;
	int	i;

	init(argc, argv, &data);
	i = 0;
	current = data.stack_a->list;
	while (current)
	{
		ft_printf("%d \n", current->value);
		current = current->next;
	}
	ft_printf("size=%d\n", data.stack_a->size);
	ft_free_nodes(&data.stack_a->list);
	free(data.stack_a);
	return (0);
}
