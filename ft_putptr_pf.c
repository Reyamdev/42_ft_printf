/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 00:36:52 by reyam             #+#    #+#             */
/*   Updated: 2026/09/30 17:38:13 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_hex_pf(unsigned long address)
{
	const char	*base = "0123456789abcdef";
	int			count;

	count = 0;
	if (address > 15)
		count += ft_putptr_hex_pf(address / 16);
	count += ft_putchar_pf(base[address % 16]);
	return (count);
}

// Print (nil) when ptr is NULL.

int	ft_putptr_pf(void *ptr)
{
	unsigned long	address;
	int				count;

	if (ptr == NULL)
		return (ft_putstr_pf("(nil)"));
	address = (unsigned long)ptr;
	count = 0;
	count += ft_putstr_pf("0x");
	count += ft_putptr_hex_pf(address);
	return (count);
}
