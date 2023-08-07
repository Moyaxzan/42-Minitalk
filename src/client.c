/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taospa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 21:39:59 by taospa            #+#    #+#             */
/*   Updated: 2023/08/07 22:59:37 by taospa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = ft_atoi(*argv);
	kill(pid, SIGUSR1);
}
