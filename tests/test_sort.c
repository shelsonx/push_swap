/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:34 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/07 18:34:07 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	show_stacks(t_data *data)
{
	t_node *current;
	t_node *current_2;

	current = data->stack_a->list;
	while (current != NULL)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
	if (data->stack_b != NULL)
	{
		current_2 = data->stack_b->list;
		while (current_2 != NULL)
		{
			ft_printf("%d ", current_2->value);
			current_2 = current_2->next;
		}
		ft_printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_data data;
	int size;
	int	*arr;

	init(argc, argv, &data);
	size = ft_size(data.stack_a->list);
	
	arr = malloc(sizeof(int *) * size);
	if (arr == NULL)
		return (-1);
	fill_array(data.stack_a->list, arr, size);
	
	if (size == 5)
		sort_five(&data);
	else if (size == 4)
		sort_four(&data);
	else if (size == 3)
		sort_three(&data);
	else if (size == 2)
		sort_two(&data);
	else
		//2 3 5 12 10 6 9 7 4 1 8 11
		sort_large(&data);
	show_stacks(&data);
	free(arr);
	free_stacks(&data);
}
