/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 00:02:39 by reyam             #+#    #+#             */
/*   Updated: 2026/09/30 00:51:50 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_pf(char format, unsigned int nb)
{
	const char	*lower_base = "0123456789abcdef";
	const char	*upper_base = "0123456789ABCDEF";
	int			count;

	count = 0;
	if (nb == 0)
	{
		count += ft_putchar_pf('0');
		return (count);
	}
	if (nb > 15)
		count += ft_puthex_pf(format, nb / 16);
	if (format == 'x')
		count += ft_putchar_pf(lower_base[nb % 16]);
	else
		count += ft_putchar_pf(upper_base[nb % 16]);
	return (count);
}
