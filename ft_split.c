/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:30:21 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/01/23 14:59:59 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		arraysize(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static size_t	definelen(char const *s, char c, int i)
{
	size_t	j;

	j = i;
	while (s[j] != c && s[j])
		j++;
	j -= i;
	return (j);
}

static void		*ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	strs = NULL;
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		nbwords;
	char	**strs;

	i = -1;
	j = -1;
	strs = NULL;
	if (!s || !c)
		return (NULL);
	nbwords = arraysize(s, c);
	if (!(strs = (char **)malloc(sizeof(char *) * (nbwords + 1))))
		return (NULL);
	while (s[++i] && j < nbwords)
	{
		if (s[i] != c)
		{
			strs[++j] = (char *)ft_substr(s, i, definelen(s, c, i));
			if (!strs[j])
				return (ft_free(strs));
		}
		i += definelen(s, c, i);
	}
	strs[nbwords] = (char*)0;
	return (strs);
}
