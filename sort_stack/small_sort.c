#include "../pushswap.h"

static size_t	find_min_pos(t_list *stack)
{
	int		min;
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

static bool	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
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

static void sort(t_list **stack_a, t_list **stack_b, size_t min_pos, size_t len)
{
	if (min_pos < len / 2)
		while (min_pos--)
			ra(stack_a);
	else
		while (min_pos++ < len)
			rra(stack_a);
	if (!is_sorted(*stack_a))
	{
			if (len > 3)
		{
			pb(stack_a, stack_b);
			sort(stack_a, stack_b, find_min_pos(*stack_a), len - 1);
		}
		else
			sort_three(stack_a);
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}

void	small_sort(t_list **stack_a, t_list **stack_b, size_t size)
{
	size_t	min_pos;
	
	min_pos = find_min_pos(*stack_a);
	if (size == 2 && (*stack_a)->number > (*stack_a)->next->number)
		sa(stack_a);
	else
		sort(stack_a, stack_b, min_pos, size);
}
