/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taospa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:13:50 by taospa            #+#    #+#             */
/*   Updated: 2023/08/07 22:56:22 by taospa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"

void	signalHandler(int sig)
{
	write(1, "Recieving signal...\n", 20);
}

int	main(void)
{
	signal(SIGUSR1, signalHandler);
	signal(SIGUSR2, signalHandler);

	ft_putnbr_fd(getgid(), 1);
	write(1, "Waiting for signal...\n", 23);
	while (1)
		pause();
	return (0);
}
