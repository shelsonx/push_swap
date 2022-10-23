/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:31:14 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/23 20:02:46 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static void	run_command(t_data *data, char *command)
{
	if ((ft_strcmp(command, "pa") == 0))
		push_a(data);
	else if ((ft_strcmp(command, "pb") == 0))
		push_b(data);
	else if ((ft_strcmp(command, "sa") == 0))
		swap_sa(data);
	else if ((ft_strcmp(command, "sb") == 0))
		swap_sb(data);
	else if ((ft_strcmp(command, "ss") == 0))
		swap_ss(data);
	else if ((ft_strcmp(command, "ra") == 0))
		rotate_a(data->stack_a);
	else if ((ft_strcmp(command, "rb") == 0))
		rotate_b(data->stack_b);
	else if ((ft_strcmp(command, "rr") == 0))
		rotate_all(data->stack_a, data->stack_b);
	else if ((ft_strcmp(command, "rra") == 0))
		reverse_rotate_a(data->stack_a);
	else if ((ft_strcmp(command, "rrb") == 0))
		reverse_rotate_b(data->stack_b);
	else if ((ft_strcmp(command, "rrr") == 0))
		reverse_rotate_all(data->stack_a, data->stack_b);
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
}

static void	sorting(t_data *data)
{
	char	*command;
	char	*line;

	line = ft_get_next_line(STDIN_FILENO);
	while (line)
	{
		close(STDOUT_FILENO);
		command = ft_substr(line, 0, ft_strlen(line) - 1);
		run_command(data, command);
		free(line);
		line = ft_get_next_line(STDIN_FILENO);
		free(command);
	}
	if (is_sorted(data->stack_a->list) && (ft_size(data->stack_b->list) == 0))
	{
		free_stacks(data);
		ft_putstr_fd("OK\n", STDERR_FILENO);
		exit(0);
	}
	ft_putstr_fd("KO\n", STDERR_FILENO);
	free_stacks(data);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init(argc, argv, &data);
	init_stack_b(&data);
	if (validate(&data) && argc > 2)
		sorting(&data);
	return (0);
}
