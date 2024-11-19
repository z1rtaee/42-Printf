/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:11:28 by bpires-r          #+#    #+#             */
/*   Updated: 2024/11/19 17:40:13 by bpires-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	int	res;
	va_list arg_lst;
	
	res = 0;
	// if (!s)
	// 	return (0);
	va_start(arg_lst, s);
	while (s)
	{
		if (*s == '%')
		{
			s++;
			
		}
		else
			write(1, &*s, 1);
		s++;
	}
}

int	str_format(const char *s, va_list arg_lst)
{
	int	res;
	int	c;

	res = 0;
	c = 0;
	if (*s == 'c')
	{
		c = va_arg(arg_lst, int)
		res = res + write(1, &c, 1)
	}
	else if (*s == 's')
		res = res + ft_putstr(va_arg(arg_lst, char *));
	else if (*s == 'd' || *s == 'i')
		res = res + ft_putnbr()
}

int	ft_putstr(char *s)
{
	int res;

	res = 0;
	while (*s)
	{
		res = res + write(1, &*s, 1);
		s++;
	}
	return (res);
}

int	ft_putnbr(char *s, long n, int base)
{
	int	res;
	int	c;

	res = 0;
	if (n < 0 && base == 10)
	{
		write (1, "-", 1);
		n = -n;
		if (n > 0)
			ft_putnbr(n / 10);
		c = '0' + (n % 10);
		res = res + write(1, &c, 1);
	}
	if (n < 0 && base == 16)
	{
		write (1, "-", 1);
		n = -n;
		if (n > 0)
			ft_putnbr(n / 16);
		c = '0' + (n % 16);
		res = res + write(1, &c, 1);
	}
	return (res);
}
