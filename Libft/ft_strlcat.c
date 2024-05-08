/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <gsaladri@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:30:30 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:30:31 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	i = d_len;
	j = 0;
	if (i >= size || size == 0)
		return (size + s_len);
	while (src[j] && j < size - 1 - i)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (d_len + s_len);
}
