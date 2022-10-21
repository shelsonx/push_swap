/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:28:34 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/21 17:51:33 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		size;

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
	return (0);
}
