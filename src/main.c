/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 03:25:30 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/27 03:25:42 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *list;
	t_node *current;

	int	i;

	list = NULL;
	i = 0;
	while (++i < argc)
		ft_add_back(&list, ft_new(ft_atoi(argv[i])));
	current = list;
	while (current)
	{
		ft_printf("%d \n", current->value);
		current = current->next;
	}
	ft_free_nodes(&list);
}
