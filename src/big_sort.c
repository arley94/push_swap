/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:59:17 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/03 17:26:48 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_stack_node *a, t_stack_node *b)
{
	set_index_and_half(a);
	set_index_and_half(b);
	set_targets(a, b);
	set_prices(a, b);
}

t_stack_node	*get_cheapest_node(t_stack_node *stack)
{
	t_stack_node	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->push_price < cheapest->push_price)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	both_until_top(t_stack_node **a, t_stack_node **b,
				t_stack_node *best)
{
	while (*a != best->target && *b != best)
	{
		if (best->half == UP)
			rr(a, b);
		else
			rrr(a, b);
	}
}

void	until_top(t_stack_node **stack, t_stack_node *top, int stack_nb)
{
	while (*stack != top)
	{
		if (stack_nb == 0)
		{
			if (top->half == UP)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (top->half == UP)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	push_chepeast(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*best;

	best = get_cheapest_node(*b);
	if (best->half == best->target->half)
		both_until_top(a, b, best);
	until_top(a, best->target, 0);
	until_top(b, best, 1);
	pa(b, a);
}

void	big_sort(t_stack_node **a, t_stack_node **b)
{
	int	stack_len;

	stack_len = ft_stack_len(*a);
	while (stack_len > 3 && !ft_is_stack_sorted(*a))
	{
		pb(a, b);
		stack_len--;
	}
	if (!ft_is_stack_sorted(*a) && stack_len == 3)
		small_sort(a);
	while (*b)
	{
		init_stacks(*a, *b);
		push_chepeast(a, b);
	}
	set_index_and_half(*a);
	until_top(a, smallest_in_stack(*a), 0);
}
