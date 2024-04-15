#include "../pushswap.h"

void	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
}
