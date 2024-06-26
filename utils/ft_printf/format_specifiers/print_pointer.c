/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:12:42 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/18 22:20:38 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ptrlen(uintptr_t p)
{
	int	len;

	len = 0;
	while (p != 0)
	{
		len++;
		p /= 16;
	}
	return (len);
}

static void	put_pointer(uintptr_t p)
{
	if (p >= 16)
	{
		put_pointer(p / 16);
		put_pointer(p % 16);
	}
	else
	{
		if (p <= 9)
			print_char(p + '0');
		else
			print_char(p - 10 + 'a');
	}
}

int	print_pointer(uintptr_t p)
{
	int	ptr_len;

	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		ptr_len = write(1, "0x", 2);
		put_pointer(p);
		ptr_len += ptrlen(p);
	}
	return (ptr_len);
}
