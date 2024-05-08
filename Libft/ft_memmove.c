/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:30:43 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/10 20:30:44 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*memsrc;
	unsigned char		*memdest;

	memsrc = (const unsigned char *)src;
	memdest = (unsigned char *)dest;
	if (memsrc == memdest || n == 0)
		return (dest);
	if (memdest < memsrc || memdest >= (memsrc + n))
	{
		while (n--)
			*memdest++ = *memsrc++;
	}
	else
	{
		memdest += n - 1;
		memsrc += n - 1;
		while (n--)
			*memdest-- = *memsrc--;
	}
	return (dest);
}
