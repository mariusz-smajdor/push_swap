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
	last->prev = new->number;
	while (last->next)
	{
		last->next->prev = last->number;
		last = last->next;
	}
	new->prev = last->number;
	last->next = new;
}
