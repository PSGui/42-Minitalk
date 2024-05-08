/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:26:23 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/24 12:26:23 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_hexa_helper(unsigned int n, char uplow, int *contagem)
{
	char	*low;
	char	*upp;

	low = "0123456789abcdef";
	upp = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_hexa_helper(n / 16, uplow, contagem);
		n = n % 16;
	}
	if (uplow == 'X')
	{
		write(1, &upp[n], 1);
		*contagem += 1;
	}
	else
	{
		write(1, &low[n], 1);
		*contagem += 1;
	}
}

void	ft_hexa(unsigned int nbr, char uplow, int *contagem)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		*contagem += 1;
		return ;
	}
	ft_hexa_helper(nbr, uplow, contagem);
}
