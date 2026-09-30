/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 01:08:41 by reyam             #+#    #+#             */
/*   Updated: 2026/09/30 17:24:37 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_specifier(char c)
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

static int	ft_pf_format(va_list args, char specifier)
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
