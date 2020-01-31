/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:00:21 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/01/23 20:34:21 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		nbr_rec_fd(int n, int fd)
{
	char m;

	if (n > 9)
	{
		m = n % 10 + '0';
		nbr_rec_fd((n / 10), fd);
	}
	else
		m = n + 48;
	write(fd, &m, 1);
}

void			ft_putnbr_fd(int nb, int fd)
{
	if (fd < 0)
		return ;
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			write(fd, "-", 1);
		}
		nbr_rec_fd(nb, fd);
	}
}
