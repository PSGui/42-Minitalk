/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <gsaladri@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:30:36 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:30:38 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;

	d = dest;
	s = src;
	n = size;
	while (n > 1 && *s)
	{
		*d++ = *s++;
		n--;
	}
	if (n > 0)
		*d = '\0';
	while (*s)
		s++;
	return (s - src);
}
