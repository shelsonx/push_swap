/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:28:23 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/21 17:48:31 by sjhony-x         ###   ########.fr       */
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

static int	contains_duplicate(t_node *list)
{
	int	size;
	int	*arr;
	int	i;

	size = ft_size(list);
	arr = malloc(sizeof(int *) * size);
	if (arr == NULL)
		return (-1);
	fill_array(list, arr, size);
	quick_sort(arr, 0, size -1);
	i = 0;
	while (i < (size -1))
	{
		if (arr[i] == arr[i +1])
		{	
			free(arr);
			return (TRUE);
		}
		i++;
	}
	free(arr);
	return (FALSE);
}

static char	*skip_zero(char *str)
{
	while (*str && str[0] == '0' && ft_isdigit(str[1]))
		str++;
	return (str);
}

static int	is_number(t_data *data)
{
	char	*str;
	char	*arg;
	int		i;

	i = 0;
	while (i++ < data->argc -1)
	{
		str = ft_itoa(ft_atoi(data->argv[i]));
		arg = skip_zero(data->argv[i]);
		if (ft_strncmp(arg, str, ft_strlen(data->argv[i])) != 0)
		{
			free(str);
			return (FALSE);
		}
		free(str);
	}
	return (TRUE);
}

int	validate(t_data *data)
{
	if (contains_duplicate(data->stack_a->list) || !is_number(data))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		free_stacks(data);
		return (FALSE);
	}
	else if (data->argc == 1 || is_sorted(data->stack_a->list))
	{
		free_stacks(data);
		exit(1);
	}
	return (TRUE);
}
