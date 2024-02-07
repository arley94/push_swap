/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:35:21 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/07 10:44:26 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

void	ft_free_and_error(t_stack_node **a, t_stack_node **b, char *str)
{
	ft_stack_clear(a);
	ft_stack_clear(b);
	free(str);
	ft_error();
}

void	ft_execute_commands(t_stack_node **a, t_stack_node **b, char *str)
{
	if (ft_strncmp(str, "sa\n", 5) == 0)
		sa(a, FALSE);
	else if (ft_strncmp(str, "sb\n", 5) == 0)
		sb(b, FALSE);
	else if (ft_strncmp(str, "ss\n", 5) == 0)
		ss(a, b, FALSE);
	else if (ft_strncmp(str, "pa\n", 5) == 0)
		pa(b, a, FALSE);
	else if (ft_strncmp(str, "pb\n", 5) == 0)
		pb(a, b, FALSE);
	else if (ft_strncmp(str, "ra\n", 5) == 0)
		ra(a, FALSE);
	else if (ft_strncmp(str, "rb\n", 5) == 0)
		rb(b, FALSE);
	else if (ft_strncmp(str, "rr\n", 5) == 0)
		rr(a, b, FALSE);
	else if (ft_strncmp(str, "rra\n", 5) == 0)
		rra(a, FALSE);
	else if (ft_strncmp(str, "rrb\n", 5) == 0)
		rrb(b, FALSE);
	else if (ft_strncmp(str, "rrr\n", 5) == 0)
		rrr(a, b, FALSE);
	else
		ft_free_and_error(a, b, str);
}

void	ft_read_commands(t_stack_node **a, t_stack_node **b, int fd)
{
	char	*str;

	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		ft_execute_commands(a, b, str);
		free(str);
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
	ft_read_commands(&a, &b, 0);
	if (ft_is_stack_sorted(a) && (b == NULL))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}
