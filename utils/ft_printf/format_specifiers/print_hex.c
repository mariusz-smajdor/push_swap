/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:12:49 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/18 22:20:32 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_hex(unsigned int n, int c)
{
	char	hex[100];
	char	digit;
	int		hex_len;
	int		i;

	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	while (n != 0)
	{
		if (n % 16 < 10)
			digit = n % 16 + '0';
		else
			digit = n % 16 - 10 + c;
		hex[i++] = digit;
		n /= 16;
	}
	hex_len = i;
	while (i > 0)
		write(1, &hex[--i], 1);
	return (hex_len);
}
