/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:34 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/05 01:27:03 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	main(int argc, char **argv)
{
	t_data data;
	t_node *current;
	t_node *current_2;
	int size;

	
	init(argc, argv, &data);
	size = ft_size(data.stack_a->list);
	if (is_sorted(data.stack_a->list))
		ft_printf("Yes, is sorted\n");
	else
		ft_printf("No, is not sorted\n");
	ft_printf("****************************************\n");
	if (size == 5)
		sort_five(&data);
	else if (size == 4)
		sort_four(&data);
	else if (size == 3)
		sort_three(&data);
	else if (size == 2)
		sort_two(&data);
	ft_printf("****************************************\n");

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
	if (is_sorted(data.stack_a->list))
		ft_printf("Yes, is sorted\n");
	else
		ft_printf("No, is not sorted\n");
	free_stacks(&data);	
}
