/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:34 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/20 22:15:16 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data data;
	int size;

	init(argc, argv, &data);
	if (validate(&data))
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
		exit(1);
	}
	return (0);
}
