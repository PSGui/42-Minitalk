/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatspecifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:26:12 by gsaladri          #+#    #+#             */
/*   Updated: 2023/10/24 12:26:14 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_formatspecifier(char specifier, va_list args, int *contagem)

{
	if (specifier == 'd' || specifier == 'i')
		ft_nbr(va_arg(args, int), contagem);
	else if (specifier == 'u')
		ft_unsigned(va_arg(args, unsigned int), contagem);
	else if (specifier == 'c')
		ft_char(va_arg(args, int), contagem);
	else if (specifier == 's')
		ft_str(va_arg(args, char *), contagem);
	else if (specifier == 'p')
		ft_pointer(va_arg(args, unsigned long), contagem);
	else if (specifier == 'x')
		ft_hexa(va_arg(args, int), 'x', contagem);
	else if (specifier == 'X')
		ft_hexa(va_arg(args, int), 'X', contagem);
	else if (specifier == '%')
		ft_char('%', contagem);
}

/*
No format specifier, utilizando ifs vemos qual e a flag a ser utilizada.
Dependedo da flag chama-se a funcao necessaria.

A parte mais imporante e a utilizacao do va_arg, que permite que possa passar o
argumento que estava no printf

para a minha funcao utilizando va_arg(args, var_type).
				       /\       /\
					|	 |
					|     Uma especie de type cast 
					|	para enviar para a
					| funcao o tipo de variavel correta
					|
				args foi a variavel definida na funcao
				    ft_printf utilizando va_list
*/
