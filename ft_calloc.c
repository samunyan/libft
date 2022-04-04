/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:41:23 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 13:41:25 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;
	size_t	i;
	size_t	dstsize;

	dstsize = count * size;
	dst = malloc(dstsize);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < dstsize)
	{
		*((char *)(dst + i)) = '\0';
		i++;
	}
	return (dst);
}
