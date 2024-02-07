/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:09:52 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/07 11:26:13 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi_special(char *str_nb, int *nb)
{
	int		sign;
	int		i;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	if (str_nb[0] == '-' || str_nb[0] == '+')
	{
		if (str_nb[0] == '-')
			sign = -1;
		i++;
	}
	while (str_nb[i])
	{
		result = result * 10 + str_nb[i++] - '0';
		if ((result * sign) > INT_MAX
			|| (result * sign) < INT_MIN)
			return (0);
	}
	result = result * sign;
	*nb = result;
	return (1);
}
