/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:14:59 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/18 22:20:39 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	put_number(unsigned int *p_n, char *numbers)
{
	int	n_len;
	int	i;

	i = -1;
	while (++i, *p_n > 0)
	{
		numbers[i] = (*p_n % 10) + '0';
		*p_n /= 10;
	}
	n_len = i;
	while (--i, i >= 0)
		write(1, &numbers[i], 1);
	return (n_len);
}

int	print_unsigned_number(unsigned int n)
{
	char			numbers[11];
	unsigned int	*p_n;
	int				i;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	p_n = &n;
	return (put_number(p_n, numbers));
}
