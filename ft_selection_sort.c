#include "libft.h"

void	ft_selection_sort(int a[], int n)
{
	int	i;
	int j;
	int	min;

	i = 0;
	while (i < n)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			if (a[j] < a[min])
				min = j;
			j++;
		}
		ft_swap(&a[i], &a[min]);
		i++;
	}
}
