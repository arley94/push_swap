/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:59:17 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/04 12:41:18 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	until_top(t_stack_node **stack, t_stack_node *top, t_stack_nb stack_nb)
{
	while (*stack != top)
	{
		if (stack_nb == A)
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

void	push_chepeast(t_stack_node **dst, t_stack_node **src,
				t_stack_nb push_to)
{
	t_stack_node	*best;

	best = get_cheapest_node(*src);
	if (best->half == best->target->half)
		both_until_top(dst, src, best);
	until_top(dst, best->target, push_to);
	until_top(src, best, !push_to);
	if (push_to == A)
		pa(src, dst);
	else
		pb(src, dst);
}

void	big_sort(t_stack_node **a, t_stack_node **b)
{
	int	stack_len;

	stack_len = ft_stack_len(*a);
	if (stack_len > 3)
	{
		pb(a, b);
		stack_len--;
	}
	while (stack_len > 3 && !ft_is_stack_sorted(*a))
	{
		init_stacks(*b, *a, B);
		push_chepeast(b, a, B);
		stack_len--;
	}
	if (!ft_is_stack_sorted(*a) && stack_len == 3)
		small_sort(a);
	while (*b)
	{
		init_stacks(*a, *b, A);
		push_chepeast(a, b, A);
	}
	set_index_and_half(*a);
	until_top(a, get_stack_max_min(*a, SMALLEST_NODE), 0);
}
