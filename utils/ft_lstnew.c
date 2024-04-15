#include "../pushswap.h"

t_list	*ft_lstnew(int n)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->number = n;
	new->next = NULL;
	return (new);
}
