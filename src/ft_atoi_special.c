/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:09:52 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/01/30 11:10:19 by acoto-gu         ###   ########.fr       */
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
		result = result * 10 + str_nb[i++] - '0';
	result = result * sign;
	if (result < INT_MIN || result > INT_MAX)
		return (0);
	*nb = result;
	return (1);
}
