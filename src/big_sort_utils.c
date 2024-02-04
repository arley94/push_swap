/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:57:13 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/04 12:41:04 by acoto-gu         ###   ########.fr       */
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

void	set_targets_to_a(t_stack_node *a, t_stack_node *b)
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
			b->target = get_stack_max_min(a, SMALLEST_NODE);
		b = b->next;
	}
}

void	set_targets_to_b(t_stack_node *b, t_stack_node *a)
{
	long			biggest_smallest;
	t_stack_node	*b_aux;

	while (a)
	{
		biggest_smallest = LONG_MIN;
		b_aux = b;
		while (b_aux)
		{
			if ((b_aux->nb < a->nb) && (b_aux->nb > biggest_smallest))
			{
				biggest_smallest = b_aux->nb;
				a->target = b_aux;
			}
			b_aux = b_aux->next;
		}
		if (biggest_smallest == LONG_MIN)
			a->target = get_stack_max_min(b, BIGGEST_NODE);
		a = a->next;
	}
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
			b->push_price = ft_get_biggest(price_a, price_b);
		else
			b->push_price = price_a + price_b;
		b = b->next;
	}
}

void	init_stacks(t_stack_node *dst, t_stack_node *src, t_stack_nb dst_stack)
{
	set_index_and_half(dst);
	set_index_and_half(src);
	if (dst_stack == A)
		set_targets_to_a(dst, src);
	else
		set_targets_to_b(dst, src);
	set_prices(dst, src);
}
