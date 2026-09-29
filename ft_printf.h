/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reyam <reyam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 01:09:14 by reyam             #+#    #+#             */
/*   Updated: 2026/09/30 01:02:37 by reyam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *str);
int	ft_putnbr_pf(int nb);
int	ft_putunsigned_pf(unsigned int nb);
int	ft_puthex_pf(char format, unsigned int nb);
int	ft_putptr_pf(void *ptr);

int	ft_printf(const char *format, ...);

#endif
