/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sl_lstadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:56:02 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 19:56:03 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sl_lstadd_back(t_sl_list **lst, t_sl_list *new)
{
	t_sl_list	*current;

	if (!*lst)
	{
		ft_sl_lstadd_front(lst, new);
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
	new->next = NULL;
}
