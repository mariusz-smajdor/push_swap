/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:15:17 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/20 19:36:48 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

int	calculate_rotation_ab(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		i;

	i = calculate_rrarrb_b(a, b, a->number);
	tmp = a;
	while (tmp)
	{
		if (i > calculate_rarb_b(a, b, tmp->number))
			i = calculate_rarb_b(a, b, tmp->number);
		if (i > calculate_rrarrb_b(a, b, tmp->number))
			i = calculate_rrarrb_b(a, b, tmp->number);
		if (i > calculate_rarrb_b(a, b, tmp->number))
			i = calculate_rarrb_b(a, b, tmp->number);
		if (i > calculate_rrarb_b(a, b, tmp->number))
			i = calculate_rrarb_b(a, b, tmp->number);
		tmp = tmp->next;
	}
	return (i);
}

int	calculate_rotation_ba(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		i;

	i = calculate_rrarrb_a(a, b, b->number);
	tmp = b;
	while (tmp)
	{
		if (i > calculate_rarb_a(a, b, tmp->number))
			i = calculate_rarb_a(a, b, tmp->number);
		if (i > calculate_rrarrb_a(a, b, tmp->number))
			i = calculate_rrarrb_a(a, b, tmp->number);
		if (i > calculate_rarrb_a(a, b, tmp->number))
			i = calculate_rarrb_a(a, b, tmp->number);
		if (i > calculate_rrarb_a(a, b, tmp->number))
			i = calculate_rrarb_a(a, b, tmp->number);
		tmp = tmp->next;
	}
	return (i);
}
