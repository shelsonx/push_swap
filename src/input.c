/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:14:17 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/24 22:07:13 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_last(t_node *lst)
{
	if (!lst)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_last(*lst);
	last->next = new;
}

void	ft_free_nodes(t_node **lst)
{
	t_node	*next;

	if (!lst)
		return ;
	next = *lst;
	while (next)
	{
		next = next->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

void	init_stack_a(t_node **list, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->value = value;
	node->next = NULL;
	ft_add_back(list, node);
}

int main(int argc, char **argv)
{
	t_node *list;
	t_node *current;

	int	i;

	list = NULL;
	i = 0;
	while (++i < argc)
		init_stack_a(&list, ft_atoi(argv[i]));

	current = list;
	while (current)
	{
		ft_printf("%d \n", current->value);
		current = current->next;
	}
	ft_free_nodes(&list);
}
