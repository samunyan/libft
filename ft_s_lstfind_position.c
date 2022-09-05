#include "libft.h"

int	ft_s_lstfind_position(t_s_list *lst, t_s_list *node)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst == node)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}