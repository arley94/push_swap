/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:37:48 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/04 14:35:24 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <signal.h>
# include "../libs/libft/libft.h"
# include "../libs/libftprintf/ft_printf.h"

/* ************************************************************************** */
/*                                 DATA_TYPES                                 */
/* ************************************************************************** */

typedef enum e_stack_pos
{
	UP,
	DOWN
}				t_stack_pos;

typedef enum e_stack_number
{
	A,
	B
}				t_stack_nb;

typedef enum e_node_limit_value
{
	SMALLEST_NODE,
	BIGGEST_NODE
}				t_node_limit_value;

typedef struct s_stack_node
{
	int					nb;
	int					idx;
	int					push_price;
	t_stack_pos			half;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}					t_stack_node;

/* ************************************************************************** */
/*                                 PARSE-ARGS                                 */
/* ************************************************************************** */

void			ft_parse_args(char **argv, t_stack_node **stack_a);
int				ft_atoi_special(char *str_nb, int *nb);

/* ************************************************************************** */
/*                                ERRORS-FREE                                 */
/* ************************************************************************** */

void			ft_free_str_arr(char **str_arr);
void			ft_stack_clear(t_stack_node **stack);
int				ft_check_dup(t_stack_node *stack_a, int nb);

/* ************************************************************************** */
/*                                STACK UTILS                                 */
/* ************************************************************************** */

t_stack_node	*ft_last_node(t_stack_node *stack);
void			ft_add_node_back(t_stack_node **stack, t_stack_node *new);
int				ft_stack_len(t_stack_node *stack);
int				ft_is_stack_sorted(t_stack_node *stack);
t_stack_node	*get_stack_max_min(t_stack_node *stack,
					t_node_limit_value max_min);

/* ************************************************************************** */
/*                                ALGORITHMS                                  */
/* ************************************************************************** */

void			small_sort(t_stack_node **a);
void			big_sort(t_stack_node **a, t_stack_node **b);

/* ************************************************************************** */
/*                               BIG_SORT_UTILS                               */
/* ************************************************************************** */

void			set_index_and_half(t_stack_node *stack);
void			set_targets_to_a(t_stack_node *a, t_stack_node *b);
void			set_targets_to_b(t_stack_node *b, t_stack_node *a);
void			set_prices(t_stack_node *a, t_stack_node *b);
void			init_stacks(t_stack_node *dst, t_stack_node *src,
					t_stack_nb dst_stack);

/* ************************************************************************** */
/*                                   COMMANDS                                 */
/* ************************************************************************** */

void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **b, t_stack_node **a);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif