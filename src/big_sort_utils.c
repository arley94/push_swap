/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:57:13 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/03 14:29:20 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_index_and_half(t_stack_node *stack)
{
	int	i;
	int	center;

	center = ft_stack_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->idx = i;
		if (i <= center)
			stack->half = UP;
		else
			stack->half = DOWN;
		i++;
		stack = stack->next;
	}
}

t_stack_node	*smallest_in_stack(t_stack_node *a)
{
	t_stack_node	*smallest;

	smallest = a;
	while (a)
	{
		if (smallest->nb > a->nb)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}

void	set_targets(t_stack_node *a, t_stack_node *b)
{
	long			smallest_biggest;
	t_stack_node	*a_aux;

	while (b)
	{
		smallest_biggest = LONG_MAX;
		a_aux = a;
		while (a_aux)
		{
			if ((a_aux->nb > b->nb) && (a_aux->nb < smallest_biggest))
			{
				smallest_biggest = a_aux->nb;
				b->target = a_aux;
			}
			a_aux = a_aux->next;
		}
		if (smallest_biggest == LONG_MAX)
			b->target = smallest_in_stack(a);
		b = b->next;
	}
}

int	get_biggest(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	set_prices(t_stack_node *a, t_stack_node *b)
{
	int				price_a;
	int				price_b;
	t_stack_node	*aux_b;

	aux_b = b;
	while (b)
	{
		if (b->half == UP)
			price_b = b->idx;
		else
			price_b = ft_stack_len(aux_b) - b->idx;
		if (b->target->half == UP)
			price_a = b->target->idx;
		else
			price_a = ft_stack_len(a) - b->target->idx;
		if (b->half == b->target->half)
			b->push_price = get_biggest(price_a, price_b);
		else
			b->push_price = price_a + price_b;
		b = b->next;
	}
}
