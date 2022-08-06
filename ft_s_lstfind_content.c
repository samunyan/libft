#include "libft.h"

t_s_list	*ft_s_lstfind_content(t_s_list *lst, void *content)
{
	while (lst)
	{
		if (lst->content == content)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}