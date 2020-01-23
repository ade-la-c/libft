/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:42:11 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/01/23 15:39:18 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		strlgt(int n)
{
	int	count;

	count = 1;
	if (!n)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9 && ++count)
		n /= 10;
	return (count);
}

char			*ft_itoa(int n)
{
	long int	nb;
	char		*str;
	int			lgt;
	int			end;

	nb = n;
	lgt = strlgt(nb);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char *)malloc(sizeof(char) * (lgt + 1))))
		return (NULL);
	if (nb < 0)
		nb *= -1;
	end = lgt + 1;
	while (lgt > 0)
	{
		str[--lgt] = (nb % 10) + 48;
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	str[end] = '\0';
	return (str);
}
