/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <gsaladri@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:29:25 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:29:28 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*mem;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	mem = (char *)malloc((i + 1) * sizeof(char));
	if (!mem)
		return (0);
	while (j < i)
	{
		mem[j] = s[j];
		j++;
	}
	mem[j] = '\0';
	return (mem);
}
