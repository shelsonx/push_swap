/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjhony-x <sjhony-x@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:14:43 by sjhony-x          #+#    #+#             */
/*   Updated: 2022/09/27 03:27:58 by sjhony-x         ###   ########.fr       */
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


//Functions to operations node
t_node	*ft_last(t_node *lst);
void	ft_add_back(t_node **lst, t_node *new);
void	ft_add_front(t_node **lst, t_node *new);
int		ft_size(t_node *lst);
void	ft_free_nodes(t_node **lst);
t_node	*ft_new(int value);

#endif