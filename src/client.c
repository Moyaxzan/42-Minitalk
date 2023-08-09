/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taospa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:39:59 by taospa            #+#    #+#             */
/*   Updated: 2023/08/09 15:17:05 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"

int	send_sig(char *str, pid_t pid)
{
	int	i;
	int	ref;

	i = 0;
	ref = 0b10000000;
	while (*str)
	{
		while (i < 8)
		{
			if (!(*str & ref))
			{
				//write(1, "0", 1);
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
				//write(1, "1", 1);
			}
			i++;
			ref = ref >> 1;
			usleep(500);
		}
		//write(1, "\n", 1);
		ref = 0b10000000;
		i = 0;
		str++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (write(2, "Invalid argments\n", 17));
	pid = ft_atoi(argv[1]);
	if (send_sig(argv[2], pid))
		write(1, "Signal sent\n", 12);
	else
		write(2, "Error sending signal, make sure you used a valid PID\n", 53);
	return (0);
}
