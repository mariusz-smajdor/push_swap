#include "pushswap.h"

int main(int ac, char **av)
{
	t_list	*stack_a;
	bool	is_split;

	is_split = ac == 2;
	if (ac < 2)
		ft_error();
	if (is_split)
		av = ft_split(av[1], ' ');
	validate_input(av, is_split);
	stack_a = init_stack(av, is_split);
	return (0);
}
