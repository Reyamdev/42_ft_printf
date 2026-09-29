/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 20:29:44 by reyam             #+#    #+#             */
/*   Updated: 2026/09/30 00:49:54 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Each recursive call has its own local count in its own stack frame.
** Each call returns its count to the previous caller, where it is added
** to the total count of printed characters.
*/

int	ft_putnbr_pf(int nb)
{
	int		count;
	long	num;

	count = 0;
	num = nb;
	if (num == 0)
	{
		count += ft_putchar_pf('0');
		return (count);
	}
	if (num < 0)
	{
		count += ft_putchar_pf('-');
		num *= -1;
	}
	if (num > 9)
		count += ft_putnbr_pf(num / 10);
	count += ft_putchar_pf((num % 10) + '0');
	return (count);
}
