/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:49:20 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/20 21:53:40 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_arrfree(char **arr, bool error)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	while (i--)
		free(arr[i]);
	free(arr);
	if (error)
		ft_error();
}
