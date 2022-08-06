#include "libft.h"

size_t ft_s_lstfind_position(t_s_list *lst, t_s_list *node)
{
	size_t i;

	i = 0;
	while (lst)
	{
		i++;
		if (lst == node)
			return (i);
		lst = lst->next;
	}
	return (0);
}