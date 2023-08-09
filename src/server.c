/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taospa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:13:50 by taospa            #+#    #+#             */
/*   Updated: 2023/08/09 14:17:48 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"

void	signal_handler(int sig)
{
	static char	character;

	if (sig == SIGUSR1)
		character = character << 1;
	else if (sig == SIGUSR2)
		character = (character << 1) + 1;
	else if (!sig)
	{
		write(1, &character, 1);
		character = 0b00000000;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					i;

	i = 1;
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, 0x0);
	sigaction(SIGUSR2, &sa, 0x0);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
	{
		pause();
		if (i == 8)
		{
			i = 0;
			signal_handler(0);
		}
		i++;
	}
	return (0);
}
