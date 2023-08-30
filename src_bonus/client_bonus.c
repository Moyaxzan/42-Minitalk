/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taospa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:39:59 by taospa            #+#    #+#             */
/*   Updated: 2023/08/30 15:33:05 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"

int	send_nul_byte(pid_t pid)
{
	int	success;
	int	i;

	success = 0;
	i = 0;
	while (i < 8)
	{
		success = kill(pid, SIGUSR1);
		if (success == -1)
			return (-1);
		i++;
		usleep(400);
	}
	return (0);
}


int	send_int(pid_t server_pid, int int_to_send)
{
	unsigned int	ref;
	int				success;

	success = 0;
	ref = 0b10000000000000000000000000000000;
	while (ref)
	{
		if (!(int_to_send & ref))
			success = kill(server_pid, SIGUSR1);
		else
			success = kill(server_pid, SIGUSR2);
		ref = ref >> 1;
		usleep(400);
	}
	return (success);
}

int	send_sig(char *str, pid_t pid)
{
	int	ref;
	int	success;

	success = 0;
	ref = 0b10000000;
	if (send_int(pid, getpid()) == -1 || send_int(pid, ft_strlen(str)) == -1)
		return (-1);
	while (*str)
	{
		while (ref)
		{
			if (!(*str & ref))
				success = kill(pid, SIGUSR1);
			else
				success = kill(pid, SIGUSR2);
			ref = ref >> 1;
			if (success == -1)
				return (-1);
			usleep(400);
		}
		ref = 0b10000000;
		str++;
	}
	success = send_nul_byte(pid);
	return (success);
}

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		exit(write(1, "Signal sent successfully\n", 25));
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, 0x0);
	if (argc != 3)
		return (write(2, "Invalid argments\n", 17));
	pid = ft_atoi(argv[1]);
	if (pid && send_sig(argv[2], pid) != -1)
		pause();
	else
		write(2, "Error sending signal, make sure you used a valid PID\n", 53);
	return (0);
}
