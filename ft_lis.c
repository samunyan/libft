/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:17:51 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 17:17:56 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*ft_get_len_of_increasing_sequences(int a[], int n)
{
	int	*len_arr;
	int	i;
	int	j;

	len_arr = malloc(sizeof(int) * n);
	if (!len_arr)
		return (NULL);
	i = 0;
	while (i < n)
		len_arr[i++] = 1;
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (a[j] > a[i])
				len_arr[j] = ft_max(len_arr[j], len_arr[i] + 1);
			j++;
		}
		i++;
	}
	return (len_arr);
}

static int	ft_get_len_of_lis(int len_arr[], int n)
{
	int	max_len;
	int	i;

	max_len = 0;
	i = 0;
	while (i < n)
	{
		max_len = ft_max(max_len, len_arr[i]);
		i++;
	}
	return (max_len);
}

int	ft_lis(int a[], int n)
{
	int	*len_arr;
	int	max_len;

	len_arr = ft_get_len_of_increasing_sequences(a, n);
	if (!len_arr)
		return (0);
	max_len = ft_get_len_of_lis(len_arr, n);
	free(len_arr);
	return (max_len);
}
