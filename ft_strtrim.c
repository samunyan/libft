/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:17:54 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 17:17:55 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	len;

	start = 0;
	while (*s1 && ft_strchr(set, *s1) != NULL)
	{
		start++;
		s1++;
	}
	len = 0;
	while (*s1 && ft_strchr(set, *s1) == NULL)
	{
		s1++;
		len++;
	}
	res = ft_substr(s1, start, len);
	return (res);
}
