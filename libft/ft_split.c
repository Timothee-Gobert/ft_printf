/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 08:45:46 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/11 10:12:12 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeall(char	**back)
{
	while (*back)
	{
		free(*back);
		back++;
	}
}

static int	ft_countwords(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

static int	ft_allocsplit(char *s, char **back, char c)
{
	int		i;
	char	**s2;

	s2 = back;
	i = 0;
	while (*s)
	{
		if (*s != c)
			i++;
		if (i > 0 && (*s == c || *(s + 1) == '\0'))
		{
			*s2 = malloc(sizeof(char) * (i + 1));
			if (!*s2++)
			{
				ft_freeall(back);
				return (0);
			}
			i = 0;
		}
		s++;
	}
	return (1);
}

static void	ft_fillsplit(char **back, char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c)
			back[i][j++] = *s;
		if (j > 0 && (*s == c || *(s + 1) == '\0'))
		{
			back[i++][j] = '\0';
			j = 0;
		}
		s++;
	}
	back[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**back;

	i = ft_countwords((char *) s, c) + 1;
	back = malloc(sizeof(char *) * i);
	if (!back)
		return (NULL);
	if (!ft_allocsplit((char *) s, back, c))
	{
		free(back);
		return (NULL);
	}
	ft_fillsplit(back, (char *) s, c);
	return (back);
}
