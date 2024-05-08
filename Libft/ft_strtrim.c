/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <gsaladri@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:28:39 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:28:39 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*mem;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (i < ft_strlen(s1) - j &&
		ft_strchr(set, s1[ft_strlen(s1) - j - 1]) != 0)
		j++;
	len = ft_strlen(s1) - j - i;
	mem = (char *)malloc((len + 1) * sizeof(char));
	if (!mem)
		return (0);
	ft_strlcpy(mem, s1 + i, len + 1);
	return (mem);
}
