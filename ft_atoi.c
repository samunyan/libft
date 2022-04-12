/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:41:11 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 13:41:16 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	nb;
	int		sign;

	str = ft_skip_space(str);
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	nb = 0;
	while ('0' <= *str && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	nb *= sign;
	return ((int)nb);
}
