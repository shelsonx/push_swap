/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:32:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/07 22:06:30 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	steps_to_push_smallests(t_data *data)
{
	set_mid_value(data);
	push_before_mid(data);
	push_after_mid(data);
	skip_bigger_mid(data);
	push_before_mid(data);
	skip_bigger_mid(data);
	skip_equals_mid(data);
	push_before_mid(data);
}

void	put_smallests_to_b(t_data *data)
{
	if (ft_size(data->stack_a->list) == 2)
	{
		sort_two(data);
		return ;
	}
	steps_to_push_smallests(data);
	put_smallests_to_b(data);
}

void	sort_large(t_data *data)
{
	put_smallests_to_b(data);
}
