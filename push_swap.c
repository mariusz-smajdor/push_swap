#include "pushswap.h"

void    validate_digits(char **av)
{
    size_t i;
    size_t j;

    i = 1;
    j = 0;
    while (av[i])
    {
        while (av[i][j])
        {
            if (!ft_isdigit(av[i][j]))
            {
                ft_printf("Error\n");
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void    validate_input(char **av)
{
    validate_digits(av);
}

int main(int ac, char **av) {
    t_list *stack_a;
    t_list *stack_b;

    if (ac < 2)
        return (1);
    stack_a = malloc(sizeof(t_list));
    stack_b = malloc(sizeof(t_list));
    if (!stack_a || !stack_b)
        return (1);
    validate_input(av);
    return (0);
}

