/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:47:04 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:26:18 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*mem;

	i = 0;
	mem = (const unsigned char *)s;
	while (i < n)
	{
		if (mem[i] == (unsigned char)c)
		{
			return ((void *)&mem[i]);
		}
		i++;
	}
	return (0);
}
