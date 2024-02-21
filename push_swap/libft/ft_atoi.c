/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcortes- <rcortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:46:31 by rcortes-          #+#    #+#             */
/*   Updated: 2024/01/16 14:46:41 by rcortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *nptr)
{
	int			i;
	int			ifneg;
	long int	num;

	num = 0;
	i = 0;
	ifneg = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			ifneg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + (nptr[i++] - '0');
	return (num * ifneg);
}

/*while (nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == ' ' || nptr[i] == '\r')
		i++;
Vigilar i++ de la penultima linea*/