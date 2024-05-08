/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <gsaladri@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:29:16 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:29:17 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*mem;

	j = 0;
	if (s == 0 || f == 0)
		return (0);
	i = ft_strlen((char *)s);
	mem = (char *)malloc((i + 1) * sizeof(char));
	if (!mem)
		return (0);
	while (s[j] != '\0')
	{
		mem[j] = f(j, s[j]);
		j++;
	}
	mem[i] = '\0';
	return (mem);
}
