/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:45:14 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/10 09:09:36 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if ((unsigned char)p[i] == (unsigned char)c)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
