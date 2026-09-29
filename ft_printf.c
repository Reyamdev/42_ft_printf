/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 01:08:41 by reyam             #+#    #+#             */
/*   Updated: 2026/09/30 01:06:08 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Here are the requirements:
// • Do not implement the buffer management of the original printf().
// • Your function has to handle the following conversions: cspdiuxX%
// • Your function will be compared against the original printf().
// • You must use the command ar to create your library.
// Using the libtool command is forbidden.
// •Your libftprintf.a has to be created at the root of your repository.
// •Your header file must be named ft_printf.h and must contain the prototype of
// your ft_printf() function.

// You have to implement the following conversions:
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.

//https://www.geeksforgeeks.org/c/variadic-functions-in-c/

//only call va_end once we finished looping the format,
//it cleans up the previously initialized va_list.

int	ft_is_specifier(char c)
{
	const char	*specifiers = "cspdiuxX%";

	while (*specifiers)
	{
		if (c == *specifiers)
			return (1);
		specifiers++;
	}
	return (0);
}

int	ft_pf_format(va_list args, char specifier)
{
	if (specifier == 'c')
		return (ft_putchar_pf(va_arg(args, int)));
	if (specifier == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	if (specifier == '%')
		return (ft_putchar_pf('%'));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_pf(va_arg(args, int)));
	if (specifier == 'u')
		return (ft_putunsigned_pf(va_arg(args, unsigned int)));
	if (specifier == 'x' || specifier == 'X')
		return (ft_puthex_pf(specifier, va_arg(args, unsigned int)));
	if (specifier == 'p')
		return (ft_putptr_pf(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (0);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && format[1] && ft_is_specifier(format[1]))
		{
			format++;
			count += ft_pf_format(args, *format);
		}
		else
			count += ft_putchar_pf(*format);
		format++;
	}
	va_end(args);
	return (count);
}
