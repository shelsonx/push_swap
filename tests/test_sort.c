/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:34 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/28 17:14:15 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	main(int argc, char **argv)
{
	t_data data;
	t_node *current;
	t_node *current_2;
	
	init(argc, argv, &data);
	
	reverse_rotate_a(data.stack_a);
	push_b(&data);
	swap_sa(&data);
	push_b(&data);
	swap_ss(&data);
	push_b(&data);
	swap_sb(&data);
	push_a(&data);
	swap_sb(&data);
	push_a(&data);
	push_a(&data);

	ft_printf("STACK A SIZE=%d\n", ft_size(data.stack_a->list));
	current = data.stack_a->list;
	while (current != NULL)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\nSTACK B SIZE=%d \n", ft_size(data.stack_b->list));
	current_2 = data.stack_b->list;
	while (current_2 != NULL)
	{
		ft_printf("%d ", current_2->value);
		current_2 = current_2->next;
	}
	ft_printf("\n");
	free_stacks(&data);	
}
