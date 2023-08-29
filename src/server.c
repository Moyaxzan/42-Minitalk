/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taospa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:13:50 by taospa            #+#    #+#             */
/*   Updated: 2023/08/29 12:06:52 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"

int	g_in_len = 1;

void	ft_putstr_ui(unsigned int *str)
{
	while (str && *str)
	{
		write(1, str, 1);
		str++;
	}
}

void	signal_handler(int sig)
{
	static unsigned int	character;
	static unsigned int	*str;
	static int			i;

	if (sig == SIGUSR1)
		character = character << 1;
	else if (sig == SIGUSR2)
		character = (character << 1) + 1;
	else if (!sig)
	{
		if (g_in_len)
			str = ft_calloc(character + 1, sizeof(unsigned int));
		else if (!character)
		{
			ft_putstr_ui(str);
			write(1, "\n", 1);
			free(str);
			str = 0x0;
			g_in_len = 1;
			i = 0;
		}
		else if (str)
			str[i++] = character;
		character = 0b00000000000000000000000000000000;
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
		if ((i == 8 && !g_in_len) || (i == 32 && g_in_len))
		{
			signal_handler(0);
			if (i == 32)
				g_in_len = 0;
			i = 0;
		}
		i++;
	}
	return (0);
}
