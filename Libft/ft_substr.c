/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <gsaladri@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:28:14 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:28:15 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (!s)
		return (0);
	if (start > s_len)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	mem = (char *)malloc((len + 1) * sizeof(char));
	if (!mem)
		return (0);
	while (i < len && s[start] != '\0')
	{
		mem[i] = s[start];
		i++;
		start++;
	}
	mem[i] = '\0';
	return (mem);
}
