#include "libft.h"

int	ft_binary_search(int *arr, int size, int n)
{
	int	low;
	int	high;
	int	mid;
	int	guess;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		guess = arr[mid];
		if (guess == n)
			return (mid);
		if (guess > n)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (-1);
}
