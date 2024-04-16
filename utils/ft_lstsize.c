#include "../pushswap.h"

size_t	ft_lstsize(t_list *stack)
{
	size_t size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
