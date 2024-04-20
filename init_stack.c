/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:37:15 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/20 21:50:32 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*new;
	size_t	i;

	stack = NULL;
	i = 0;
	while (av[i])
	{
		new = ft_lstnew(ft_atoi(av[i]));
		if (!new)
			ft_lstfree(&stack, true);
		ft_lstadd_back(&stack, new);
		i++;
	}
	if (ac == 2)
		ft_arrfree(av);
	return (stack);
}
