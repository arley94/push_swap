/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 08:34:00 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/05 07:12:58 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack_node **head)
{
	if (head == NULL || ft_stack_len(*head) < 2)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a, t_bool print_command)
{
	swap(a);
	if (print_command)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, t_bool print_command)
{
	swap(b);
	if (print_command)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, t_bool print_command)
{
	swap(a);
	swap(b);
	if (print_command)
		ft_printf("ss\n");
}
