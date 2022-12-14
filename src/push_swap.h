/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:14:43 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/10/21 04:47:12 by sjhony-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libs/libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_node
{
	int				index;
	int				position;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*list;
	int				size;
	int				mid;
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
void	ft_add_back(t_node **lst, t_node *new_node);
void	ft_add_front(t_node **lst, t_node *new_node);
int		ft_size(t_node *lst);
void	ft_free_nodes(t_node **lst);
t_node	*ft_new(int value, int index);

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
int		find_smallest_position(t_node *list);
int		find_biggest_position(t_node *list);
int		find_biggest_index(t_node *list);
int		find_index(t_node *list, int value);
void	fill_array(t_node *list, int *arr, int size);

//sort small
void	sort_two(t_data *data);
void	sort_three(t_data *data);

//positions
void	set_targets_pos(t_stack *stack_a, t_stack *stack_b);
void	set_indexes(t_node *list);
void	set_positions(t_node *list);

//costs
void	set_costs(t_data *data);
t_node	*get_cheaper(t_node *list);

//sort large
void	sort_large(t_data *data);

//sort large utils
void	run_actions(t_data *data);

//validate
int		is_sorted(t_node *list);
int		validate(t_data *data);

//quick sort
void	quick_sort(int *arr, int low, int high);

//adjust stack
void	adjust_stack_a(t_stack *stack_a);

#endif