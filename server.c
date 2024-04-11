/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:47:28 by aakouhar          #+#    #+#             */
/*   Updated: 2024/02/23 15:43:28 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

struct s_minitalk	g_global;

void	ft_handler(int signum)
{
	if (signum == SIGUSR1)
		g_global.c |= (1 << (7 - g_global.index));
	g_global.index++;
	if (g_global.index == 8)
	{
		write(1, &g_global.c, 1);
		g_global.index = 0;
		g_global.c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "pid server is --> ", 18);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, &ft_handler);
	signal(SIGUSR2, &ft_handler);
	while (42)
	{
		pause();
	}
	return (0);
}
