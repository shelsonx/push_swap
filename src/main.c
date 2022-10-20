/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:34 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/20 23:07:26 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data data;
	int size;

	if (argc == 1)
		return (1);
	init(argc, argv, &data);
	if (validate(&data) && argc > 2)
	{
		size = ft_size(data.stack_a->list);
		if (size == 2)
			sort_two(&data);
		else if (size == 3)
			sort_three(&data);
		else if (size > 3)
			sort_large(&data);
		free_stacks(&data);
	}
	else
	{
		ft_putstr_fd("Error!\n", 2);
		free_stacks(&data);
		exit(1);
	}
	return (0);
}
