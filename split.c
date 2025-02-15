/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayyad <melayyad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:10:10 by melayyad          #+#    #+#             */
/*   Updated: 2025/02/10 17:12:25 by melayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	counter(char const *s, char c)
{
	int	words;
	int	flag;

	words = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			words++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (words);
}

static char	*ft_copy(char const *s, char c)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(ft_len(s, c) + 1);
	if (!dst)
		return (NULL);
	while (*s == c)
		s++;
	while (*s && *s != c)
	{
		dst[i++] = *s;
		s++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_free(char **src, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(src[i++]);
	free(src);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**src;

	i = 0;
	src = malloc(sizeof(char *) * (counter(s, c) + 1));
	if (!s || !src)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			src[i] = ft_copy(s, c);
			if (!src[i])
				return (ft_free(src, i));
			i++;
			while (*s != c && *s)
				s++;
		}
	}
	src[i] = NULL;
	return (src);
}
