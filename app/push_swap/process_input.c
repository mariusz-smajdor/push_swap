/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:04:37 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/27 23:46:50 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	validate_number(char **av, char *v, bool splitted)
{
	size_t	i;

	i = 0;
	while (v[i])
	{
		if (i == 0 && ft_issign(v[i]) && ft_isdigit(v[i + 1]))
			i++;
		if (!ft_isdigit(v[i]))
			{
				if (splitted)
					ft_arrfree(av, true);
				else
					ft_error();
			}
		i++;
	}
}

static void	validate_limits(char **av, char *v, bool splitted)
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
	if ((len > max_len || (len == max_len && ft_strncmp(v, limit, max_len) > 0)))
	{
		if (splitted)
			ft_arrfree(av, true);
		else
			ft_error();
	}
}

static void	validate_repetition(char **av, bool splitted)
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
			{
				if (splitted)
					ft_arrfree(av, true);
				else
					ft_error();
			}
			j++;
		}
		i++;
	}
}

char	**process_input(int ac, char **av)
{
	size_t	i;
	char	**new_av;
	bool	splitted;

	splitted = false;
	if (ac < 2)
		ft_error();
	if (ac == 2)
	{
		new_av = ft_split(*av, ' ');
		av = new_av;
		splitted = true;
	}
	if (av[0] == NULL)
		ft_arrfree(av, true);
	i = 0;
	while (av[i])
	{
		validate_number(av, av[i], splitted);
		validate_limits(av, av[i], splitted);
		i++;
	}
	validate_repetition(av, splitted);
	return (av);
}
