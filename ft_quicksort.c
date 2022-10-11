/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:10:39 by samunyan          #+#    #+#             */
/*   Updated: 2022/09/29 17:10:40 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_partition(int a[], int lo, int hi)
{
	int	i;
	int	j;

	i = lo + 1;
	j = hi;
	while (1)
	{
		while (a[i] < a[lo])
		{
			if (i == hi)
				break ;
			i++;
		}
		while (a[j] > a[lo])
		{
			if (j == lo)
				break ;
			j--;
		}
		if (i >= j)
			break ;
		ft_swap(&a[i], &a[j]);
	}
	ft_swap(&a[lo], &a[j]);
	return (j);
}

void	ft_quicksort(int a[], int lo, int hi)
{
	int	pivot;

	if (hi <= lo)
		return ;
	pivot = ft_partition(a, lo, hi);
	ft_quicksort(a, lo, pivot - 1);
	ft_quicksort(a, pivot + 1, hi);
}
