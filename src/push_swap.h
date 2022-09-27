/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:14:43 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/27 18:09:20 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libs/libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*list;
	int				size;
}	t_stack;

typedef struct s_data
{
	int				argc;
	char			**argv;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}	t_data;

//Functions to operations node
t_node	*ft_last(t_node *lst);
void	ft_add_back(t_node **lst, t_node *new);
void	ft_add_front(t_node **lst, t_node *new);
int		ft_size(t_node *lst);
void	ft_free_nodes(t_node **lst);
t_node	*ft_new(int value);

//init data
void	init(int argc, char **argv, t_data *data);

//swap operations
void	swap_sa(t_data *data);
void	swap_sb(t_data *data);
void	swap_ss(t_data* data);

#endif