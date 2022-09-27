/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:25:30 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/27 18:37:37 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *current;
	t_node *current_2;
	t_data data;
	int	i;

	init(argc, argv, &data);

	data.stack_b = malloc(sizeof(t_stack));
	data.stack_b->list = NULL;
	i = 0;
	while (++i < data.argc)
		ft_add_back(&data.stack_b->list, 
			ft_new(ft_atoi(data.argv[i])));

	/* swap_sa(&data);
	swap_sb(&data); */
	swap_ss(&data);
	current = data.stack_a->list;
	current_2 = data.stack_b->list;
	while (current)
	{
		ft_printf("stack A= %d \n", current->value);
		ft_printf("stack B= %d \n", current_2->value);
		current = current->next;
		current_2 = current_2->next;
	}
	ft_printf("size=%d\n", data.stack_a->size);
	ft_free_nodes(&data.stack_a->list);
	ft_free_nodes(&data.stack_b->list);
	free(data.stack_a);
	free(data.stack_b);
	return (0);
}
