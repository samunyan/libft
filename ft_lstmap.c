/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:03:49 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 20:03:50 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new;
	t_list	*tmp;

	new_head = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			while (new_head)
			{
				tmp = new_head->next;
				ft_lstdelone(new_head, del);
				new_head = tmp;
			}
			return (NULL);
		}
		ft_lstadd_back(&new_head, new);
		lst = lst->next;
	}
	return (new_head);
}
