/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgobert <tgobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:15:04 by tgobert           #+#    #+#             */
/*   Updated: 2025/11/10 09:08:46 by tgobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;
	t_list	*start;
	void	*dst_content;

	if (!f || !del || !lst)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	if (!start)
		return (NULL);
	lst = lst->next;
	dst = start;
	while (lst != NULL)
	{
		dst_content = f(lst->content);
		dst = dst->next;
		dst = ft_lstnew(dst_content);
		if (!dst)
		{
			ft_lstclear(&dst, del);
			return (NULL);
		}
		ft_lstadd_back(&start, dst);
		lst = lst->next;
	}
	return (start);
}
