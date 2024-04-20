/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:43:42 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/20 19:36:48 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	use_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->number != c && get_index_b(*b, c) > 0)
			rr(a, b);
		while ((*a)->number != c)
			ra(a);
		while (get_index_b(*b, c) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->number != c && get_index_a(*a, c) > 0)
			rr(a, b);
		while ((*b)->number != c)
			rb(b);
		while (get_index_a(*a, c) > 0)
			ra(a);
		pa(a, b);
	}
	return (-1);
}

int	use_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->number != c)
			ra(a);
		while (get_index_b(*b, c) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while (get_index_a(*a, c) > 0)
			ra(a);
		while ((*b)->number != c)
			rrb(b);
		pa(a, b);
	}
	return (-1);
}

int	use_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->number != c)
			rra(a);
		while (get_index_b(*b, c) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while (get_index_a(*a, c) > 0)
			rra(a);
		while ((*b)->number != c)
			rb(b);
		pa(a, b);
	}
	return (-1);
}

int	use_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->number != c && get_index_b(*b, c) > 0)
			rrr(a, b);
		while ((*a)->number != c)
			rra(a);
		while (get_index_b(*b, c) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->number != c && get_index_a(*a, c) > 0)
			rrr(a, b);
		while ((*b)->number != c)
			rrb(b);
		while (get_index_a(*a, c) > 0)
			rra(a);
		pa(a, b);
	}
	return (-1);
}
