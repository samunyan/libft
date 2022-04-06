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

	start = 0;
	res = (char *)s1;
	while (*s1 && ft_strchr(set, *s1) != NULL)
	{
		start++;
		s1++;
	}
	while (*(s1 + 1))
		s1++;
	while (*s1 && ft_strchr(set, *s1) != NULL)
		s1--;
	res = ft_substr(res, start, s1 - res);
	return (res);
}
