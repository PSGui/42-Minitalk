/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <gsaladri@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:27:48 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:27:49 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*mem;

	len1 = 0;
	len2 = 0;
	i = 0;
	if (!(s1 && s2))
		return (0);
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	mem = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!mem)
		return (0);
	while (*s1)
		mem[i++] = *s1++;
	while (*s2)
		mem[i++] = *s2++;
	mem[i] = '\0';
	return (mem);
}
