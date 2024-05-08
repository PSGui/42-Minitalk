/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <gsaladri@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:29:52 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:29:52 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	const char	*l;
	size_t		temp;

	if (!*little)
		return ((char *)big);
	while (*big && len != 0)
	{
		b = big;
		l = little;
		temp = len;
		while (*b && *l && *b == *l)
		{
			if (temp == 0)
				break ;
			b++;
			l++;
			temp--;
		}
		if (!*l)
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
