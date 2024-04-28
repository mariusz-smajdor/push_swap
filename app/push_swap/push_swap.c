/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:59:49 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/20 21:56:04 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = init_stack(ac, process_input(ac, av + 1));
	if (!stack_a)
		ft_lstfree(&stack_a, true);
	sort_stack(&stack_a);
	ft_lstfree(&stack_a, false);
	return (0);
}
