/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:42:55 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/01/23 15:22:10 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	i = -1;
	while (s2[++i])
		s1[len + i] = s2[i];
	s1[len + i] = '\0';
	return (s1);
}
