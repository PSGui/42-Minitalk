/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:04:09 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/10 14:04:14 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int r)
{
	int		i;
	char	*p;

	p = (char *)str;
	i = 0;
	while ((unsigned char)str[i] != (unsigned char)r)
	{
		if (!str[i])
			return (0);
		i++;
		p++;
	}
	return (p);
}
