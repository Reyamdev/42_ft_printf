/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 16:24:01 by reyam             #+#    #+#             */
/*   Updated: 2026/09/28 19:49:59 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Print "(null)" when the string pointer is NULL.

int	ft_putstr_pf(char *str)
{
	int	count;

	if (str == NULL)
		return (write(1, "(null)", 6));
	count = 0;
	while (*str)
	{
		count += ft_putchar_pf(*str);
		str++;
	}
	return (count);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("hello % kek");
// }
