/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:14:17 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/24 05:44:00 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack_a(t_list **list, int value)
{
	t_list *node;

	if (!list)
		return;
	node = malloc(sizeof(t_list *));
	node->content = malloc(sizeof(int *));
	*((int *)node->content) = value;
	ft_lstadd_back(list, node);
}

int main(int argc, char **argv)
{
	t_list *list;
	int	i;

	list = NULL;
	i = 0;
	while (++i < argc)
		set_stack_a(&list, ft_atoi(argv[i]));

	while (list != NULL)
	{
		ft_printf("%d \n", *(int *)list->content);
		list = list->next;
	}
}
