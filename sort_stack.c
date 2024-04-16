#include "pushswap.h"

static void sort_three(t_list **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
	if ((*stack_a)->number > (*stack_a)->next->next->number)
		rra(stack_a);
	if ((*stack_a)->next->number > (*stack_a)->next->next->number)
		sa(&(*stack_a)->next);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	size_t	size;

	size = ft_lstsize(*stack_a);
	if (size == 2 && (*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
	if (size == 3)
		sort_three(stack_a);
}
