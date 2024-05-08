/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:53:27 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/24 21:53:28 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_pointer_helper_v3(int *contagem)
{
	write(1, "0x", 2);
	*contagem += 2;
}

static void	ft_pointer_helper(unsigned long n, int *contagem)
{
	int		i;
	int		nbr;
	char	*digits;
	char	str[16];

	i = 0;
	nbr = 0;
	digits = "0123456789abcdef";
	while (n > 0)
	{
		nbr = n % 16;
		str[i++] = digits[nbr];
		n /= 16;
	}
	ft_pointer_helper_v3(contagem);
	while (i > 0)
	{
		write(1, &str[--i], 1);
		*contagem += 1;
	}
}

void	ft_pointer(unsigned long nbr, int *contagem)
{
	if (nbr == 0)
	{
		write(1, "(nil)", 5);
		*contagem += 5;
		return ;
	}
	ft_pointer_helper(nbr, contagem);
}

/*
int 	main()
{	
	int	contagem;

	contagem = 0;
	write(1, "\n", 1); 
	ft_pointer(0, &contagem);
	write(1, "\n", 1); 
	ft_pointer(4294967295, &contagem);
	write(1, "\n", 1); 
	ft_pointer(-2147483648, &contagem);
	write(1, "\n", 1); 
	ft_pointer(2147483647, &contagem);
	return (0);
}*/
