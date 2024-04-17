#include "../pushswap.h"

static void	sort_three(t_list **stack_a)
{
	if ((*stack_a)->number > (*stack_a)->next->next->number 
		&& (*stack_a)->number > (*stack_a)->next->number)
		ra(stack_a);
	if ((*stack_a)->next->number > (*stack_a)->next->next->number)
		rra(stack_a);
	if ((*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
}

void	small_sort(t_list **stack_a, t_list **stack_b, size_t size)
{
	if (size == 2 && (*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
	if (size == 3)
		sort_three(stack_a);
}