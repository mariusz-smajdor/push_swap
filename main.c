#include "pushswap.h"

int main(int ac, char **av)
{
    t_list	*stack_a;
    t_list	*stack_b;

    if (ac < 2)
        return (1);
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
    if (!validate_input(av + 1))
        return (1);
    if (!validate_repetition(av + 1))
        return (1);
    return (0);
}

