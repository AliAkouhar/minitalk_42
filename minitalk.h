/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:47:14 by aakouhar          #+#    #+#             */
/*   Updated: 2024/02/23 15:38:57 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h> 

struct	s_minitalk
{
	char	c;
	int		index;
};

void	ft_putchar(char c);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);

#endif
