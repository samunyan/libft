#include "libft.h"

static int	*ft_get_len_of_increasing_sequences(int a[], int n)
{
	int	*len_arr;
	int	i;
	int	j;

	len_arr = malloc(sizeof(int) * n);
	if (!len_arr)
		return (NULL);
	ft_memset(len_arr, 1, n);
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

static int	ft_get_end_index_of_lis(int n, int len_arr[])
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = i;
	max = len_arr[i];
	while (i < n)
	{
		if (len_arr[i] > max)
		{
			max = len_arr[i];
			j = i;
		}
		i++;
	}
	return (j);
}

static int	*ft_get_lis_helper(int a[], int n, int *len_arr, int max_len)
{
	int	*lis;
	int	i;
	int	j;

	lis = malloc(sizeof(int) * (max_len + 1));
	if (!lis)
		return (NULL);
	lis[0] = max_len;
	i = ft_get_end_index_of_lis(n, len_arr);
	lis[max_len] = a[i];
	j = i - 1;
	while (j >= 0)
	{
		if (a[j] < a[i] && len_arr[j] == len_arr[i] - 1)
		{
			i = j;
			lis[--max_len] = a[i];
		}
		j--;
	}
	return (lis);
}

int	*ft_get_lis(int a[], int n)
{
	int	*lis;
	int	*len_arr;
	int	max_len;

	len_arr = ft_get_len_of_increasing_sequences(a, n);
	if (!len_arr)
		return (NULL);
	max_len = ft_get_len_of_lis(len_arr, n);
	lis = ft_get_lis_helper(a, n, len_arr, max_len);
	free(len_arr);
	return (lis);
}
