/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:26:49 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/01/30 11:20:09 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_int(void *nb)
{
	ft_printf("%d\n", *((int *)nb));
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*temp_a;

	stack_a = NULL;
	if (argc > 1)
	{
		ft_parse_args(argv + 1, &stack_a);
		temp_a = stack_a;
		while (temp_a)
		{
			ft_printf("%d\n", temp_a->nb);
			temp_a = temp_a->next;
		}
		ft_stack_clear(&stack_a);
	}
	return (0);
}
