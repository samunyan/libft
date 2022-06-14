/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_lstclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:56:32 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 19:56:33 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sl_lstclear(t_sl_list **lst, void (*del)(void*))
{
	t_sl_list	*current;
	t_sl_list	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		ft_sl_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
