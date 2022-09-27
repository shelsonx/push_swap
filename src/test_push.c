/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:25:30 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/27 23:47:20 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *current;
	t_node *current_2;
	t_data data;

	init(argc, argv, &data);

	push_b(&data);
	push_b(&data);
	push_b(&data);

	if (data.stack_b != NULL)
	{
		current_2 = data.stack_b->list;
		while (current_2)
		{
			ft_printf("stack B= %d \n", current_2->value);
			current_2 = current_2->next;
		}
		ft_printf("size stack_b=%d\n", data.stack_b->size);
	}

	current = data.stack_a->list;
	while (current)
	{
		ft_printf("stack A= %d \n", current->value);
		current = current->next;
	}
	
	ft_free_nodes(&data.stack_a->list);
	free(data.stack_a);
	if (data.stack_b != NULL)
	{
		ft_free_nodes(&data.stack_b->list);
		free(data.stack_b);
	}
	return (0);
}
