/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:52:22 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/02 09:49:00 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	small_sort(t_stack_node **a)
{
	if (((*a)->nb > (*a)->next->nb) && ((*a)->nb > (*a)->next->next->nb))
		ra(a);
	else if (((*a)->next->nb > (*a)->nb)
		&& ((*a)->next->nb > (*a)->next->next->nb))
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}
