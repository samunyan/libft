#include "../libft.h"

static void	set_int_arr_to(int a[], int n, int val)
{
	int	i;
	i = 0;
	while (i < n)
	{
		a[i] = 1;
		i++;
	}
}

static void test(int a[], int n)
{
	set_int_arr_to(a, n, 1);
}

int main()
{
	int	*len_arr;
	int n;

	n = 5;
	len_arr = malloc(sizeof(int) * n);
	if (!len_arr)
		return (EXIT_FAILURE);
	test(len_arr, n);
	int i = 0;
	while (i < n)
	{
		ft_printf("%d ", len_arr[i]);
		i++;
	}
}
