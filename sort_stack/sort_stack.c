/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:11:14 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/20 22:20:23 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if (ft_lstmin(*stack_a) == (*stack_a)->number)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (ft_lstmax(*stack_a) == (*stack_a)->number)
	{
		ra(stack_a);
		if (!is_sorted(*stack_a))
			sa(stack_a);
	}
	else
	{
		if (find_index(*stack_a, ft_lstmax(*stack_a)) == 1)
			rra(stack_a);
		else
			sa(stack_a);
	}
}

static void	sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (ft_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = calculate_rotation_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == calculate_rarb_b(*stack_a, *stack_b, tmp->number))
				i = use_rarb(stack_a, stack_b, tmp->number, 'a');
			else if (i == calculate_rrarrb_b(*stack_a, *stack_b, tmp->number))
				i = use_rrarrb(stack_a, stack_b, tmp->number, 'a');
			else if (i == calculate_rarrb_b(*stack_a, *stack_b, tmp->number))
				i = use_rarrb(stack_a, stack_b, tmp->number, 'a');
			else if (i == calculate_rrarb_b(*stack_a, *stack_b, tmp->number))
				i = use_rrarb(stack_a, stack_b, tmp->number, 'a');
			else
				tmp = tmp->next;
		}
	}
}

static t_stack	*push_and_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, &stack_b);
	if (ft_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		pb(stack_a, &stack_b);
	if (ft_lstsize(*stack_a) > 3 && !is_sorted(*stack_a))
		sort_b_till_3(stack_a, &stack_b);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	return (stack_b);
}

static t_stack	**sort_b(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = calculate_rotation_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == calculate_rarb_a(*stack_a, *stack_b, tmp->number))
				i = use_rarb(stack_a, stack_b, tmp->number, 'b');
			else if (i == calculate_rarrb_a(*stack_a, *stack_b, tmp->number))
				i = use_rarrb(stack_a, stack_b, tmp->number, 'b');
			else if (i == calculate_rrarrb_a(*stack_a, *stack_b, tmp->number))
				i = use_rrarrb(stack_a, stack_b, tmp->number, 'b');
			else if (i == calculate_rrarb_a(*stack_a, *stack_b, tmp->number))
				i = use_rrarb(stack_a, stack_b, tmp->number, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else
	{
		stack_b = push_and_sort_b(stack_a);
		stack_a = sort_b(stack_a, &stack_b);
		i = find_index(*stack_a, ft_lstmin(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->number != ft_lstmin(*stack_a))
				ra(stack_a);
		}
		else
		{
			while ((*stack_a)->number != ft_lstmin(*stack_a))
				rra(stack_a);
		}
	}
}
