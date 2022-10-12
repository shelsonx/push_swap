/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:32:05 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/12 15:28:07 by sjhony-x         ###   ########.fr       */
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

void	steps_to_pull_smallests(t_data *data)
{
	set_mid_value_stack_b(data);
	pull_before_mid(data);
	//pull_after_mid(data);
	skip_equals_mid_stack_b(data);
	skip_smallest_mid(data);
	pull_before_mid(data);
	skip_smallest_mid(data);
	//skip_equals_mid_stack_b(data);
	pull_before_mid(data);
	if (data->stack_b->list->value == data->stack_b->mid
		&& data->stack_b->list->value > data->stack_b->list->next->value)
		push_a(data);
		
}

void	add_chunk(t_data *data)
{
	ft_add_front(&data->chunks, 
		ft_new(data->stack_b->list->value));
}

void	put_smallests_to_b(t_data *data)
{
	if (ft_size(data->stack_a->list) == 2)
	{
		sort_two(data);
		return ;
	}
	steps_to_push_smallests(data);
	add_chunk(data);
	put_smallests_to_b(data);
}

void	put_biggets_to_a(t_data *data)
{
	t_node	*current;

	current = data->chunks;
	data->stack_b->size = find_index(data->stack_b->list, current->next->value) - find_index(data->stack_b->list, current->value);
	if (data->stack_b->size == 1)
		push_a(data);
	
	if (current->next)
		current = current->next;
	data->stack_b->size = find_index(data->stack_b->list, current->next->value) - find_index(data->stack_b->list, current->value);
	set_mid_value_stack_b(data);
	while (data->stack_b->list->value > data->stack_b->mid)
		push_a(data);
	if (data->stack_b->list->value < data->stack_b->list->next->value)
		swap_sb(data);
	push_a(data);
	push_a(data);	

	if (current->next)
		current = current->next;
	if (current->next == NULL)
		data->stack_b->size = ft_size(data->stack_b->list) - find_index(data->stack_b->list, current->value);
	set_mid_value_stack_b(data);
	while (data->stack_b->list->value > data->stack_b->mid)
		push_a(data);
	while (data->stack_b->list->value <= data->stack_b->mid)
		rotate_b(data->stack_b);
	while (data->stack_b->list->value > data->stack_b->mid)
		push_a(data);
	while (data->stack_b->list->value < data->stack_b->mid)
		rotate_b(data->stack_b);
	if (data->stack_b->list->value == data->stack_b->mid)
		push_a(data);
	while (data->stack_b->size--)
		push_a(data);
	//debug
	ft_printf("size=%d\n", data->stack_b->size);
	ft_printf("mid=%d\n", data->stack_b->mid);
}

void	sort_large(t_data *data)
{
	put_smallests_to_b(data);
	put_biggets_to_a(data);
}
