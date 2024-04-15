#include "pushswap.h"

int main(int ac, char **av)
{
    t_list	*stack_a;
    t_list	*stack_b;

    if (ac < 2)
        ft_error();
    if (ac == 2)
        av = ft_split(av[1], ' ');
    stack_a = malloc(sizeof(t_list));
    stack_b = malloc(sizeof(t_list));
    if (!stack_a || !stack_b)
    {
        free(stack_a);
        free(stack_b);
        return (1);
    }
    validate_input(av, ac == 2);
    return (0);
}
