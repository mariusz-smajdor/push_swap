#include "../pushswap.h"

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*last;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
}
