/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:34 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/05 17:09:24 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	main(int argc, char **argv)
{
	t_data data;
	//t_node *current;
	//t_node *current_2;
	int size;

	
	init(argc, argv, &data);
	size = ft_size(data.stack_a->list);
	if (size == 5)
		sort_five(&data);
	else if (size == 4)
		sort_four(&data);
	else if (size == 3)
		sort_three(&data);
	else if (size == 2)
		sort_two(&data);

	/* current = data.stack_a->list;
	while (current != NULL)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
	if (data.stack_b != NULL)
	{
		current_2 = data.stack_b->list;
		while (current_2 != NULL)
		{
			ft_printf("%d ", current_2->value);
			current_2 = current_2->next;
		}
		ft_printf("\n");
	} */
	free_stacks(&data);	
}
