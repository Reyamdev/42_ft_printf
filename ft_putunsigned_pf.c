/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 23:48:00 by reyam             #+#    #+#             */
/*   Updated: 2026/09/30 00:50:35 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_pf(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (ft_putchar_pf('0'));
	if (nb > 9)
		count += ft_putunsigned_pf(nb / 10);
	count += ft_putchar_pf((nb % 10) + '0');
	return (count);
}
