/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:09:40 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/01 09:31:43 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (stack == NULL || *stack == NULL || ft_stack_len(*stack) == 1)
		return ;
	last_node = ft_last_node(*stack);
	last_node->next = *stack;
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
