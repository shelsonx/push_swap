/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:31:14 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/23 00:41:34 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_command(t_data *data, char *command)
{
	if ((ft_strncmp(command, "pa", 2) == 0) && (ft_strlen(command) == 2))
		push_a(data);
	else if ((ft_strncmp(command, "pb", 2) == 0) && (ft_strlen(command) == 2))
		push_b(data);
	else if ((ft_strncmp(command, "sa", 2) == 0) && (ft_strlen(command) == 2))
		swap_sa(data);
	else if ((ft_strncmp(command, "sb", 2) == 0) && (ft_strlen(command) == 2))
		swap_sb(data);
	else if ((ft_strncmp(command, "ss", 2) == 0) && (ft_strlen(command) == 2))
		swap_ss(data);
	else if ((ft_strncmp(command, "ra", 2) == 0) && (ft_strlen(command) == 2))
		rotate_a(data->stack_a);
	else if ((ft_strncmp(command, "rb", 2) == 0) && (ft_strlen(command) == 2))
		rotate_b(data->stack_b);
	else if ((ft_strncmp(command, "rr", 2) == 0) && (ft_strlen(command) == 2))
		rotate_all(data->stack_a, data->stack_b);
	else if ((ft_strncmp(command, "rra", 3) == 0) && (ft_strlen(command) == 3))
		reverse_rotate_a(data->stack_a);
	else if ((ft_strncmp(command, "rrb", 3) == 0) && (ft_strlen(command) == 3))
		reverse_rotate_b(data->stack_b);
	else if ((ft_strncmp(command, "rrr", 3) == 0) && (ft_strlen(command) == 3))
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
	if (is_sorted(data->stack_a->list))
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
