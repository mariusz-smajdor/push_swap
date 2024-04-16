#include "pushswap.h"

static void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	size_t	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_two(stack_a);
}
