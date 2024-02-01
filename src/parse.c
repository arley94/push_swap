/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:37:20 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/01/30 11:29:15 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_add_numb_to_stack(int numb, t_stack_node **stack_a)
{
	t_stack_node	*new_stack_node;

	if (stack_a == NULL)
		return (0);
	new_stack_node = malloc(sizeof(t_stack_node));
	if (new_stack_node == NULL)
		return (0);
	new_stack_node->nb = numb;
	new_stack_node->next = NULL;
	ft_add_node_back(stack_a, new_stack_node);
	return (1);
}

int	ft_save_numbs(char **split_numbs, t_stack_node **stack_a)
{
	int	i;
	int	nb;

	i = 0;
	while (split_numbs[i])
	{
		if (ft_str_is_numeric(split_numbs[i]) == 0)
			return (0);
		if (ft_atoi_special(split_numbs[i], &nb) == 0)
			return (0);
		if (ft_check_dup(*stack_a, nb) == 0)
			return (0);
		if (ft_add_numb_to_stack(nb, stack_a) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_parse_args(char **argv, t_stack_node **stack_a)
{
	int		i;
	char	**split_numbs;

	i = 0;
	while (argv[i])
	{
		split_numbs = ft_split(argv[i], ' ');
		if (split_numbs[0] == NULL)
			ft_error();
		if (!ft_save_numbs(split_numbs, stack_a))
		{
			ft_stack_clear(stack_a);
			ft_free_str_arr(split_numbs);
			ft_error();
		}
		ft_free_str_arr(split_numbs);
		i++;
	}
}
