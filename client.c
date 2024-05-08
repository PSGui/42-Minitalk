#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "minitalk.h"

int	param_check(int argc, char *argv)
{
	int i;

	i = 0;
	if (argc != 3){
		ft_printf("Certifique-se que o número de parâmetros está correto e que segue esta lógica:\n");
		ft_printf("./cliente <PID> <string>\n");
		return (1);
	}
	if (argc == 3){
		while (argv[i] != '\0')
		{
			if (!ft_isdigit(argv[i]))
			{
				ft_printf("PID inválido! É uma sequência de números.\n");
				return (1);
			}
			i++;
		}
		return (0);
	}
	return (0);
}

void	send_sigusr(int pid, unsigned char character)
{
	int				i;
	unsigned char	t_char;

	i = 8;
	t_char = character;
	while (i > 0)
	{
		i--;
		t_char = character >> i;
		if (t_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	char	*msg;
	int	i;

	i = 0;
	if (param_check(argc, argv[1]) != 0)
    	{
        	return (1);
    	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (msg[i])
		send_sigusr(pid, msg[i++]);
	send_sigusr(pid, '\0');
	usleep(2000);
	return (0);
}