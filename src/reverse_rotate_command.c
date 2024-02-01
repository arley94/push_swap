/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:22:38 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/01 16:35:43 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (stack == NULL || *stack == NULL || ft_stack_len(*stack) == 1)
		return ;
	last_node = ft_last_node(*stack);
	last_node->next = *stack;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next->prev = last_node;
	*stack = last_node;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
