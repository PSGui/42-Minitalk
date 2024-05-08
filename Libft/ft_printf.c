/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:26:36 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/24 12:26:37 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		contagem;

	i = 0;
	contagem = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_formatspecifier(str[i], args, &contagem);
		}
		else
		{
			write(1, &str[i], 1);
			contagem += 1;
		}
		i++;
	}
	va_end(args);
	return (contagem);
}