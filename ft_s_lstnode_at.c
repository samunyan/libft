#include "libft.h"

t_s_list	*ft_s_lstnode_at(t_s_list *list, int index)
{
	int i;

	i = 0;
	while (list)
	{
		if (i == index)
			return (list);
		i++;
		list = list->next;
	}
	return (NULL);
}
