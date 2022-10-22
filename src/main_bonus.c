/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:31:14 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/22 22:06:29 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_command(t_data *data, char *command)
{
	close(STDOUT_FILENO);
	if (ft_strncmp(command, "pa\n", ft_strlen(command))== 0)
		push_a(data);
	else if(ft_strncmp(command, "pb\n", ft_strlen(command))== 0)
		push_b(data);
	else if(ft_strncmp(command, "sa\n", ft_strlen(command))== 0)
		swap_sa(data);
	else if(ft_strncmp(command, "sb\n", ft_strlen(command))== 0)
		swap_sb(data);
	else if(ft_strncmp(command, "ss\n", ft_strlen(command))== 0)
		swap_ss(data);
	else if(ft_strncmp(command, "ra\n", ft_strlen(command))== 0)
		rotate_a(data->stack_a);
	else if(ft_strncmp(command, "rb\n", ft_strlen(command))== 0)
		rotate_b(data->stack_b);
	else if(ft_strncmp(command, "rr\n", ft_strlen(command))== 0)
		rotate_all(data->stack_a, data->stack_b);
	else if(ft_strncmp(command, "rra\n", ft_strlen(command))== 0)
		reverse_rotate_a(data->stack_a);
	else if(ft_strncmp(command, "rrb\n", ft_strlen(command))== 0)
		reverse_rotate_b(data->stack_b);
	else if(ft_strncmp(command, "rrr\n", ft_strlen(command))== 0)
		reverse_rotate_all(data->stack_a, data->stack_b);
	else
		ft_putstr_fd("Error\n", STDERR_FILENO);
}

int	main(int argc, char **argv)
{
	t_data	data;
	//char	*command;
	char	*line;

	init(argc, argv, &data);
	init_stack_b(&data);
	if (validate(&data) && argc > 2)
	{
		line = ft_get_next_line(STDIN_FILENO);
		while (line)
		{
			//command = ft_substr(line, 0, ft_strlen(line)-1);
			run_command(&data, line);
			free(line);
			line = ft_get_next_line(STDIN_FILENO);
			//free(command);
		}
	}
	if (is_sorted(data.stack_a->list))
	{
		free_stacks(&data);
		ft_putstr_fd("OK\n", STDERR_FILENO);
		return (1);
	}
	ft_putstr_fd("KO\n", STDERR_FILENO);
	free_stacks(&data);
	return (0);
}
