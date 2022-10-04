/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:14:43 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/28 17:21:41 by sjhony-x         ###   ########.fr       */
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
void	init_stack_b(t_data *data);

//swap operations
void	swap_sa(t_data *data);
void	swap_sb(t_data *data);
void	swap_ss(t_data *data);

//push
void	push_b(t_data *data);
void	push_a(t_data *data);

//rotate
void	rotate_a(t_stack *stack_a);
void	rotate_b(t_stack *stack_b);
void	rotate_all(t_stack *stack_a, t_stack *stack_b);

void	reverse_rotate_a(t_stack *stack_a);
void	reverse_rotate_b(t_stack *stack_b);
void	reverse_rotate_all(t_stack *stack_a, t_stack *stack_b);

//exit
void	free_stacks(t_data *data);

//utils
int find_smallest_index(t_node *list);

//sort small
void	sort_two(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data);
void	sort_five(t_data *data);

#endif