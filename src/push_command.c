/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:38:02 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/05 07:16:37 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*node_to_push;

	if (src == NULL || dst == NULL || *src == NULL)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	if (*dst == NULL)
	{
		*dst = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dst;
		(*dst)->prev = node_to_push;
		*dst = node_to_push;
	}
}

void	pa(t_stack_node **b, t_stack_node **a, t_bool print_command)
{
	push(b, a);
	if (print_command)
		ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, t_bool print_command)
{
	push(a, b);
	if (print_command)
		ft_printf("pb\n");
}
