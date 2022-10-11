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

static void	get_number_in_str(int n, char *s)
{
	size_t	i;
	long	nb;

	ft_bzero(s, 12);
	nb = n;
	if (n < 0)
		nb = -nb;
	i = ft_get_num_len(nb, 10);
	if (n < 0)
		i++;
	if (n < 0)
		s[0] = '-';
	while (nb >= 0)
	{
		i--;
		s[i] = (nb % 10) + '0';
		nb /= 10;
		if (nb == 0)
			break ;
	}
}

int	ft_atoi_is_valid(int i, const char *str)
{
	char	check[12];
	int		is_negative;
	size_t	n;

	get_number_in_str(i, check);
	str = ft_skip_space(str);
	is_negative = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = 1;
		str++;
	}
	while (ft_strlen(str) > 1 && *str == '0')
		str++;
	n = 0;
	while (ft_isdigit(*(str + n)))
		n++;
	if (n == 0)
		return (0);
	if (is_negative)
		return (!ft_strncmp(str, check + 1, n));
	return (!ft_strncmp(str, check, n));
}

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
