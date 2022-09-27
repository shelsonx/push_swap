/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:25:30 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/28 00:38:10 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *current;
	t_data data;

	if (argc < 2)
		exit(1);

	init(argc, argv, &data);
	rotate_a(data.stack_a);
	
	current = data.stack_a->list;
	while (current)
	{
		ft_printf("%d \n", current->value);
		current = current->next;
	}
	ft_printf("size= %d \n", data.stack_a->size);
	ft_free_nodes(&data.stack_a->list);
	free(data.stack_a);
	return (0);
}
