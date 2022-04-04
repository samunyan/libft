/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:18:39 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 17:18:41 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_chars(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	long	nb;

	i = ft_count_chars(n);
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	nb = n;
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	while (nb >= 0)
	{
		i--;
		s[i] = (nb % 10) + '0';
		nb /= 10;
		if (nb == 0)
			break ;
	}
	return (s);
}
