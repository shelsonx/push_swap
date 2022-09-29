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

void	sort_three_elements(t_data *data)
{
	t_node	*nd;
	nd = data->stack_a->list;
	if (nd->value > nd->next->value && nd->next->value < nd->next->next->value && nd->next->next->value > nd->value)
		swap_sa(data);
	else if (nd->value > nd->next->value && nd->next->value > nd->next->next->value)
	{
		swap_sa(data);
		reverse_rotate_a(data->stack_a);
	}
	else if (nd->value > nd->next->value && nd->next->value < nd->next->next->value && nd->next->next->value < nd->value)
		rotate_a(data->stack_a);
	else if (nd->value < nd->next->value && nd->next->value > nd->next->next->value && nd->next->next->value > nd->value)
	{
		swap_sa(data);
		rotate_a(data->stack_a);
	}
	else if(nd->value < nd->next->value && nd->next->value > nd->next->next->value && nd->next->next->value < nd->value)
		reverse_rotate_a(data->stack_a);
}

int	main(int argc, char **argv)
{
	t_data data;
	t_node *current;
	t_node *current_2;
	
	init(argc, argv, &data);


	
	/* 3 numeros aleatorios
		-> 2 1 3
		sa

		-> 2 3 1
		sa
		rra

		-> 3 1 2
		ra

		-> 1 3 2
		sa
		ra

		-> 2 3 1
		rra
	*/
	ft_printf("****************************************\n");
	sort_three_elements(&data);
	ft_printf("****************************************\n");
	/* //42 4 21 1 0 34 13
	rotate_a(data.stack_a);
	push_b(&data);
	swap_sa(&data);
	push_b(&data);
	swap_sa(&data);
	push_b(&data);
	swap_sa(&data);
	swap_ss(&data);
	push_b(&data);
	swap_sa(&data);
	push_b(&data);
	swap_sb(&data);
	push_a(&data);
	push_a(&data);
	reverse_rotate_b(data.stack_b);
	push_a(&data);
	push_a(&data);
	push_a(&data); */

	/* //3 2 1 5 3
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
	push_a(&data); */

	ft_printf("STACK A SIZE=%d\nsorted-> ", ft_size(data.stack_a->list));
	current = data.stack_a->list;
	while (current != NULL)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
	if (data.stack_b != NULL)
	{
		ft_printf("\nSTACK B SIZE=%d \n", ft_size(data.stack_b->list));
		current_2 = data.stack_b->list;
		while (current_2 != NULL)
		{
			ft_printf("%d ", current_2->value);
			current_2 = current_2->next;
		}
		ft_printf("\n");
	}
	free_stacks(&data);	
}
