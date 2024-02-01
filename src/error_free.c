/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:03:24 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/01/30 10:34:04 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	if (str_arr == NULL)
		return ;
	while (str_arr[i])
	{
		free(str_arr[i++]);
	}
	free(str_arr);
}

void	ft_stack_clear(t_stack_node **stack)
{
	t_stack_node	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int	ft_check_dup(t_stack_node *stack_a, int nb)
{
	while (stack_a)
	{
		if (nb == stack_a->nb)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
