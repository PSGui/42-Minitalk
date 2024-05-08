#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include "Libft/libft.h"

#define STOP_CONNECTION '\0'

void	bit_handler(int bit);
void	send_bit(int pid, char *str, size_t len);
int	param_check(int argc, char *argv);

#endif