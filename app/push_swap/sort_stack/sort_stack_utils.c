/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:51:34 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/20 19:36:48 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

size_t	get_index_b(t_stack *stack_b, int to_push)
{
	t_stack	*tmp;
	size_t	i;

	i = 1;
	if (to_push > stack_b->number && to_push < ft_lstlast(stack_b)->number)
		i = 0;
	else if (to_push > ft_lstmax(stack_b) || to_push < ft_lstmin(stack_b))
		i = find_index(stack_b, ft_lstmax(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->number < to_push || tmp->number > to_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

size_t	get_index_a(t_stack *stack_a, int to_push)
{
	t_stack	*tmp;
	size_t	i;

	i = 1;
	if (to_push < stack_a->number && to_push > ft_lstlast(stack_a)->number)
		i = 0;
	else if (to_push > ft_lstmax(stack_a) || to_push < ft_lstmin(stack_a))
		i = find_index(stack_a, ft_lstmin(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->number > to_push || tmp->number < to_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}

size_t	find_index(t_stack *a, int number)
{
	size_t		i;

	i = 0;
	while (a->number != number)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

bool	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->number;
	while (stack)
	{
		if (i > stack->number)
			return (false);
		i = stack->number;
		stack = stack->next;
	}
	return (true);
}
