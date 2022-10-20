/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:57:08 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/20 15:01:49 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stacks(t_data *data, t_node *node_cheaper)
{
	while (node_cheaper->cost_a > 0 && node_cheaper->cost_b > 0)
	{
		rotate_all(data->stack_a, data->stack_b);
		node_cheaper->cost_a--;
		node_cheaper->cost_b--;
	}
	while (node_cheaper->cost_a < 0 && node_cheaper->cost_b < 0)
	{
		reverse_rotate_all(data->stack_a, data->stack_b);
		node_cheaper->cost_a++;
		node_cheaper->cost_b++;
	}
}

static void	rotate_stack(int *cost, t_stack *stack,
	void (*r)(t_stack *), void (*rr)(t_stack *))
{
	while (*cost)
	{
		if (*cost > 0)
		{
			r(stack);
			(*cost)--;
		}
		else
		{
			rr(stack);
			(*cost)++;
		}
	}
}

void	run_actions(t_data *data)
{
	t_node	*node_cheaper;

	node_cheaper = get_cheaper(data->stack_b->list);
	rotate_stacks(data, node_cheaper);
	rotate_stack(&node_cheaper->cost_a, data->stack_a,
		rotate_a, reverse_rotate_a);
	rotate_stack(&node_cheaper->cost_b, data->stack_b,
		rotate_b, reverse_rotate_b);
}
