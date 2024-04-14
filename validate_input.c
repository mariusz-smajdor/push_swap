#include "pushswap.h"

int	validate_input(char **av, int is_split)
{
	size_t	i;
	size_t	j;

	i = !is_split;
	if (av[0] == NULL)
		return (ft_printf("Error\n") - 6);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && ft_issign(av[i][j]) && ft_isdigit(av[i][j + 1]))
				j++;
			if (!ft_isdigit(av[i][j]))
				return (ft_printf("Error\n") - 6);
			j++;
		}
		i++;
	}
	return (1);
}