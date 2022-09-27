/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:25:30 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/28 01:40:01 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *current;
	t_node *current_2;
	t_data data;

	if (argc < 2)
		exit(1);

	init(argc, argv, &data);

	push_b(&data);
	push_b(&data);
	push_b(&data);
	push_b(&data);

	rotate_all(data.stack_a, data.stack_b);
	//rotate_b(data.stack_b);
	if (data.stack_b != NULL)
	{
		current_2 = data.stack_b->list;
		while (current_2)
		{
			ft_printf("stack B= %d \n", current_2->value);
			current_2 = current_2->next;
		}
		ft_printf("size stack_b=%d\n", ft_size(data.stack_b->list));
	}
	
	//rotate_a(data.stack_a);
	current = data.stack_a->list;
	while (current)
	{
		ft_printf("stack A= %d \n", current->value);
		current = current->next;
	}
	ft_printf("size stack_a= %d \n", ft_size(data.stack_b->list));
	ft_free_nodes(&data.stack_a->list);
	free(data.stack_a);

	if (data.stack_b != NULL)
	{
		ft_free_nodes(&data.stack_b->list);
		free(data.stack_b);
	}
	return (0);
}
