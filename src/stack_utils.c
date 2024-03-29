/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:28:14 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/04 12:39:56 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*ft_last_node(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_add_node_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*last;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = ft_last_node(*stack);
		last->next = new;
		new->prev = last;
	}
}

int	ft_stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int	ft_is_stack_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack_node	*get_stack_max_min(t_stack_node *stack,
					t_node_limit_value max_min)
{
	t_stack_node	*biggest_or_smallest;

	biggest_or_smallest = stack;
	while (stack)
	{
		if (max_min == BIGGEST_NODE)
		{
			if (biggest_or_smallest->nb < stack->nb)
				biggest_or_smallest = stack;
		}
		else
		{
			if (biggest_or_smallest->nb > stack->nb)
				biggest_or_smallest = stack;
		}
		stack = stack->next;
	}
	return (biggest_or_smallest);
}
