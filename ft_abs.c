#include "libft.h"

int	ft_abs(int n)
{
	if (n == INT_MIN)
		return (INT_MIN);
	if (n < 0)
		n = -n;
	return (n);
}
