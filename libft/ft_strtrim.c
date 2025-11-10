/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:51:32 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/10 09:10:29 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_set_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		nbr;
	int		temp;

	temp = -1;
	nbr = 0;
	i = 0;
	while (i < ft_strlen(s1) && temp != nbr)
	{
		temp = nbr;
		j = 0;
		while (j <= ft_strlen(set))
		{
			if (set[j] == s1[i])
			{
				nbr++;
				j = ft_strlen(set) - 1;
			}
			j++;
		}
		i++;
	}
	return (nbr);
}

static int	find_set_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		nbr;
	int		temp;

	temp = -1;
	nbr = 0;
	i = ft_strlen(s1) - 1;
	while (i > 0 && temp != nbr)
	{
		temp = nbr;
		j = 0;
		while (j <= ft_strlen(set))
		{
			if (set[j] == s1[i])
			{
				nbr++;
				j = ft_strlen(set) - 1;
			}
			j++;
		}
		i--;
	}
	return (nbr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	len;
	size_t	i;

	if (s1[0] == '\0')
		return (ft_calloc(1, sizeof(char)));
	if (set[0] == '\0')
		return (ft_strdup(s1));
	if ((size_t)find_set_start(s1, set) == ft_strlen(s1))
		return (ft_calloc(1, sizeof(char)));
	len = ft_strlen(s1) - find_set_start(s1, set) - find_set_end(s1, set);
	trimmed = malloc(sizeof(char) * len + 1);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (i < len)
	{
		trimmed[i] = s1[find_set_start(s1, set) + i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
