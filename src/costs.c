/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:56:47 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/20 14:48:44 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_total_cost(t_node *node)
{
	return (ft_abs(node->cost_a) + ft_abs(node->cost_b));
}

t_node	*get_cheaper(t_node *list)
{
	t_node	*current;
	t_node	*cheaper;

	current = list;
	cheaper = list;
	while (current->next)
	{
		if (get_total_cost(current) < get_total_cost(cheaper))
			cheaper = current;
		current = current->next;
	}
	return (cheaper);
}

static int	get_cost(int position, int size)
{
	int	mid;

	mid = size / 2;
	if (position > mid)
		return (position - size);
	return (position);
}

void	set_costs(t_data *data)
{
	int		size_a;
	int		size_b;
	t_node	*current;

	size_a = ft_size(data->stack_a->list);
	size_b = ft_size(data->stack_b->list);
	current = data->stack_b->list;
	while (current)
	{
		current->cost_a = get_cost(current->target_pos, size_a);
		current->cost_b = get_cost(current->position, size_b);
		current = current->next;
	}
}
