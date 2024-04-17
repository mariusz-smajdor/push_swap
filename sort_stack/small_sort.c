#include "../pushswap.h"

static size_t	find_min_pos(t_list *stack)
{
	size_t	min;
	size_t	pos;
	size_t	i;

	min = stack->number;
	pos = 0;
	i = 0;
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

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

static void	sort_four(t_list **stack_a, t_list **stack_b)
{
	size_t	min_pos;
	
	min_pos = find_min_pos(*stack_a);
	if (min_pos < 2)
		while (min_pos--)
			ra(stack_a);
	else
		while (min_pos++ < 4)
			rra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	small_sort(t_list **stack_a, t_list **stack_b, size_t size)
{
	if (size == 2 && (*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
	if (size == 3)
		sort_three(stack_a);
	if (size == 4)
		sort_four(stack_a, stack_b);
}