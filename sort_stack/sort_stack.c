#include "../pushswap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	size_t	size;

	size = ft_lstsize(*stack_a);
	if (size < 6)
		small_sort(stack_a, stack_b, size);
}
