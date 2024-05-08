/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <gsaladri@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:29:00 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:29:01 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*r;

	r = NULL;
	while (*str)
	{
		if (*str == (char)c)
			r = str;
		str++;
	}
	if ((char)c == *str)
		return ((char *)str);
	else
		return ((char *)r);
}
