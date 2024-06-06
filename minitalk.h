/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:48:37 by gsaladri          #+#    #+#             */
/*   Updated: 2024/06/06 16:48:41 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include "Libft/libft.h"

# define STOP_CONNECTION '\0'

void	bit_handler(int bit);
void	send_bit(int pid, char *str, size_t len);
int		param_check(int argc, char *argv);

#endif
