/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taospa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:39:59 by taospa            #+#    #+#             */
/*   Updated: 2023/08/31 11:43:02 by taospa           ###   ########.fr       */
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

int	send_len(char *str, pid_t pid)
{
	unsigned int	ref;
	size_t			len;
	int				success;

	success = 0;
	len = ft_strlen(str);
	ref = 0b10000000000000000000000000000000;
	while (ref)
	{
		if (!(len & ref))
			success = kill(pid, SIGUSR1);
		else
			success = kill(pid, SIGUSR2);
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
	if (send_len(str, pid) == -1)
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

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (write(2, "Invalid argments\n", 17));
	pid = ft_atoi(argv[1]);
	if (pid > 0 && send_sig(argv[2], pid) != -1)
		write(1, "Signal sent\n", 12);
	else
		write(2, "Error sending signal, make sure you used a valid PID\n", 53);
	return (0);
}
