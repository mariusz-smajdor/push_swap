/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotation_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:32:49 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/20 19:36:48 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../push_swap.h"

int	calculate_rarb_b(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = get_index_b(b, c);
	if (i < find_index(a, c))
		i = find_index(a, c);
	return (i);
}

int	calculate_rarrb_b(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index_b(b, c))
		i = ft_lstsize(b) - get_index_b(b, c);
	i = find_index(a, c) + i;
	return (i);
}

int	calculate_rrarb_b(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_index(a, c))
		i = ft_lstsize(a) - find_index(a, c);
	i = get_index_b(b, c) + i;
	return (i);
}

int	calculate_rrarrb_b(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index_b(b, c))
		i = ft_lstsize(b) - get_index_b(b, c);
	if ((i < (ft_lstsize(a) - find_index(a, c))) && find_index(a, c))
		i = ft_lstsize(a) - find_index(a, c);
	return (i);
}
