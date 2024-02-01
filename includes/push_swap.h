/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:37:48 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/01 08:40:59 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <signal.h>
# include "../libs/libft/libft.h"
# include "../libs/libftprintf/ft_printf.h"

/* ************************************************************************** */
/*                                 STRUCT                                     */
/* ************************************************************************** */
typedef struct s_stack_node
{
	int					nb;
	int					idx;
	int					push_price;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}					t_stack_node;

/* ************************************************************************** */
/*                                   STACK                                    */
/* ************************************************************************** */

t_stack_node	*ft_last_node(t_stack_node *stack);
void			ft_add_node_back(t_stack_node **stack, t_stack_node *new);

/* ************************************************************************** */
/*                                   PARSE                                    */
/* ************************************************************************** */

// void	ft_add_numb_to_stack(int numb, t_stack **stack_a);
// void	ft_save_numbs(char **split_numbs, t_stack **stack_a);
// //void	ft_free_str_arr(char **str_arr);
void			ft_parse_args(char **argv, t_stack_node **stack_a);
int				ft_atoi_special(char *str_nb, int *nb);
void			ft_free_str_arr(char **str_arr);
void			ft_stack_clear(t_stack_node **stack);
int				ft_check_dup(t_stack_node *stack_a, int nb);
int				ft_stack_len(t_stack_node *stack);

#endif