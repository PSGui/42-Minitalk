/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaladri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:40:30 by gsaladri          #+#    #+#             */
/*   Updated: 2024/06/06 16:40:33 by gsaladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "minitalk.h"

void	handle_signal(int signum)
{
	static unsigned char	current_char;
	static int				bit_i;

	current_char |= (signum == SIGUSR1);
	bit_i++;
	if (bit_i == 8)
	{
		if (current_char == STOP_CONNECTION)
			printf("\n");
		else
			printf("%c", current_char);
		bit_i = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

int	main(void)
{
	ft_printf ("Server initialized - PID: %d\n", getpid());
	signal (SIGUSR1, handle_signal);
	signal (SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
