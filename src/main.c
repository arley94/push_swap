/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:26:49 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/05 08:38:37 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(t_stack_node *a)
{
	while (a)
	{
		ft_printf("%d\n", a->nb);
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	ft_parse_args(argv + 1, &a);
	if (!ft_is_stack_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a, TRUE);
		else if (ft_stack_len(a) == 3)
			small_sort(&a);
		else
			big_sort(&a, &b);
	}
	ft_stack_clear(&a);
	return (0);
}
