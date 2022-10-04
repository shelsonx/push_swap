/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:28:23 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/05 01:24:33 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *list)
{
	t_node	*current;

	current = list;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}
