#include "pushswap.h"

t_list	*init_stack(char **av, bool is_split)
{
	t_list	*stack;
	t_list	*new;
	int		i;

	stack = NULL;
	i = !is_split;
	while (av[i])
	{
		new = ft_lstnew(ft_atoi(av[i]));
		if (!new)
			ft_error();
		ft_lstadd_back(&stack, new);
		i++;
	}
	return (stack);
}
