/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:47:21 by aakouhar          #+#    #+#             */
/*   Updated: 2024/02/24 16:42:39 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int	i;
	int	kill_return;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << (7 - i)))
			kill_return = kill(pid, SIGUSR1);
		else
			kill_return = kill(pid, SIGUSR2);
		if (kill_return == -1)
			exit(1);
		i++;
		usleep(1000);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		write(1, "Error you must to execute: ./client [PID] \"[MSG]\"", 48);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(1, "the PID invalide", 16);
		return (0);
	}
	while (av[2][i])
	{
		send_char(av[2][i], pid);
		i++;
	}
	send_char('\0');
	
	send_char('\n', pid);
}
