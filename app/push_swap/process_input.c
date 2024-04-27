/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:04:37 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/20 21:50:53 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	validate_number(char **av, char *v)
{
	size_t	i;

	i = 0;
	while (v[i])
	{
		if (i == 0 && ft_issign(v[i]) && ft_isdigit(v[i + 1]))
			i++;
		if (!ft_isdigit(v[i]))
			ft_arrfree(av, true);
		i++;
	}
}

static void	validate_limits(char **av, char *v)
{
	char	*limit;
	int		max_len;
	int		len;

	max_len = 11;
	if (*v == '-')
		limit = "-2147483648";
	else
	{
		if (*v == '+')
			v++;
		max_len = 10;
		limit = "2147483647";
	}
	len = ft_strlen(v);
	if (len > max_len || (len == max_len && ft_strncmp(v, limit, max_len) > 0))
		ft_arrfree(av, true);
}

static void	validate_repetition(char **av)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				ft_arrfree(av, true);
			j++;
		}
		i++;
	}
}

char	**process_input(int ac, char **av)
{
	size_t	i;
	char	**new_av;

	if (ac < 2)
		ft_error();
	if (ac == 2)
	{
		new_av = ft_split(*av, ' ');
		av = new_av;
	}
	if (av[0] == NULL)
		ft_arrfree(av, true);
	i = 0;
	while (av[i])
	{
		validate_number(av, av[i]);
		validate_limits(av, av[i]);
		i++;
	}
	validate_repetition(av);
	return (av);
}
