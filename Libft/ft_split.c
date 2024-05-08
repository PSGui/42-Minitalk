/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <gsaladri@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:28:07 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/19 20:28:07 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_splitcount(char const *s, char c)
{
	int	splits;
	int	i;

	i = 0;
	splits = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			splits++;
			continue ;
		}
		i++;
	}
	return (splits);
}

static void	ft_array_creator(char **mem, const char *s, char c)
{
	size_t		i;
	size_t		j;
	int			array_pos;

	i = 0;
	j = 0;
	array_pos = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] != c && s[i])
		{
			j++;
			i++;
		}
		if (j > 0)
		{
			mem[array_pos] = malloc(j + 1);
			if (mem[array_pos] == 0)
				return ;
			array_pos++;
			continue ;
		}
		i++;
	}
}

static void	ft_string_fill(char **mem, const char *s, char c)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] != c && s[i])
		{
			mem[j][k] = s[i];
			k++;
			i++;
		}
		if (k != 0)
		{
			mem[j][k] = '\0';
			j++;
			continue ;
		}
		i++;
	}
	mem[j] = 0;
}

static void	ft_free(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
		free(ret[i++]);
	free(ret);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		elementos;
	char	**mem;

	i = 0;
	if (!s)
		return (0);
	elementos = ft_splitcount(s, c);
	mem = (char **)malloc((elementos + 1) * sizeof(char *));
	if (!mem)
		return (0);
	ft_array_creator(mem, s, c);
	while (i < ft_splitcount(s, c))
	{
		if (mem[i] == 0)
		{
			ft_free(mem);
			return (0);
		}
		i++;
	}
	ft_string_fill(mem, s, c);
	return (mem);
}
