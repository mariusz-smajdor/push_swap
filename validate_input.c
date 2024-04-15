#include "pushswap.h"

static void	validate_number(char *av)
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		if (i == 0 && ft_issign(av[i]) && ft_isdigit(av[i + 1]))
			i++;
		if (!ft_isdigit(av[i]))
			ft_error();
		i++;
	}
}

static void validate_limits(char *av)
{
    char *limit;
    int max_len;
    int len;

	max_len = 11;
    if (*av == '-')
        limit = "-2147483648";
    else
    {
		if (*av == '+')
        	av++;
        max_len = 10;
        limit = "2147483647";
    }
	len = ft_strlen(av);
    if (len > max_len || (len == max_len && ft_strncmp(av, limit, max_len) > 0))
        ft_error();
}

static void	validate_repetition(char **av, bool is_split)
{
	size_t	i;
	size_t	j;

	i = !is_split;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				ft_error();
			j++;
		}
		i++;
	}
}

void	validate_input(char **av, bool is_split)
{
	size_t	i;

	if (av[0] == NULL)
		ft_error();
	i = !is_split;
	while (av[i])
	{
		validate_number(av[i]);
		validate_limits(av[i]);
		i++;
	}
	validate_repetition(av, is_split);
}