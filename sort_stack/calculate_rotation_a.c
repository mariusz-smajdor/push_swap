/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotation_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:25:07 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/20 19:36:48 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calculate_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = get_index_a(a, c);
	if (i < find_index(b, c))
		i = find_index(b, c);
	return (i);
}

int	calculate_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_index(b, c))
		i = ft_lstsize(b) - find_index(b, c);
	i += get_index_a(a, c);
	return (i);
}

int	calculate_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index_a(a, c))
		i = ft_lstsize(a) - get_index_a(a, c);
	i += find_index(b, c);
	return (i);
}

int	calculate_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index_a(a, c))
		i = ft_lstsize(a) - get_index_a(a, c);
	if ((i < (ft_lstsize(b) - find_index(b, c))) && find_index(b, c))
		i = ft_lstsize(b) - find_index(b, c);
	return (i);
}
