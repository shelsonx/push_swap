/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:34 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/17 13:05:59 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	show_stacks(t_data *data)
{
	t_node *current;
	t_node *current_2;

	current = data->stack_a->list;
	ft_printf("STACK A\n");
	while (current != NULL)
	{
		//ft_printf("%d ", current->value);
		ft_printf("value= %d index= %d position= %d\n", 
			current->value, current->index, current->position);
		current = current->next;
	}
	ft_printf("\n");
	if (data->stack_b != NULL)
	{
		current_2 = data->stack_b->list;
		ft_printf("STACK B\n");
		while (current_2 != NULL)
		{
			//ft_printf("%d ", current_2->value);
			ft_printf("value= %d index= %d position= %d target_pos= %d cost_b= %d cost_a= %d\n", 
				current_2->value, current_2->index, current_2->position, 
					current_2->target_pos, current_2->cost_b, current_2->cost_a);
			current_2 = current_2->next;
		}
		ft_printf("\n");
	}
	if (is_sorted(data->stack_a->list))
		ft_printf("Yes, Sorted!\n");
	else
		ft_printf("No!\n");
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
	if (size == 2)
		sort_two(&data);
	else if (size == 3)
		sort_three(&data);
	else if (size > 3)
		sort_large(&data);
	show_stacks(&data);
	free(arr);
	free_stacks(&data);
}
