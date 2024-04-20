/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:12:57 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/20 22:08:33 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	print_char(char c);
int	print_string(char *s);
int	print_pointer(uintptr_t p);
int	print_number(int n);
int	print_unsigned_number(unsigned int n);
int	print_hex(unsigned int n, int c);

#endif