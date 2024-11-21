/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:11:28 by bpires-r          #+#    #+#             */
/*   Updated: 2024/11/21 14:06:42 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *s)
{
	int	res;

	res = 0;
	if (!s)
		write(1, "(null)", 6);
	while (*s)
	{
		res = res + write(1, &*s, 1);
		s++;
	}
	return (res);
}

int	ft_putnbr(long n, int base, char *base_str)
{
	int	res;
	int	c;

	res = 0;
	if (n < 0 && base == 10)
	{
		res = res + write(1, "-", 1);
		n = -n;
	}
	if (n >= base)
		res = res + ft_putnbr(n / base, base, base_str);
	c = '0' + (n % base);
	res = res + write(1, &c, 1);
	return (res);
}

int	ft_putptr(unsigned long int p, int prefix, char *base_str)
{
	int		res;
	char	c;

	res = 0;
	if (!p)
		return (ft_putstr("(nil)"));
	if (prefix == 1)
		res = res + write(1, "0x", 2);
	if (p >= 16)
		res = res + ft_putptr(p / 16, 0, base_str);
	c = '0' + (p % 16);
	res = res + write(1, &c, 1);
	return (res);
}

int	ft_format(const char *s, va_list arg_lst)
{
	int	res;
	int	c;

	res = 0;
	c = 0;
	if (*s == 'c')
	{
		c = va_arg(arg_lst, int);
		res = res + write(1, &c, 1);
	}
	else if (*s == 's')
		res = res + ft_putstr(va_arg(arg_lst, char *));
	else if (*s == 'd' || *s == 'i')
		res = res + ft_putnbr(va_arg(arg_lst, int), 10, DECIMAL);
	else if (*s == 'u')
		res = res + ft_putnbr(va_arg(arg_lst, unsigned int), 10, DECIMAL);
	else if (*s == 'X')
		res = res + ft_putnbr(va_arg(arg_lst, unsigned int), 16, HEXA_UP);
	else if (*s == 'x')
		res = res + ft_putnbr(va_arg(arg_lst, unsigned int), 16, HEXA_LOW);
	else if (*s == 'p')
		res = res + ft_putptr(va_arg(arg_lst, unsigned long int), 1, HEXA_LOW);
	return (res);
}

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	arg_lst;
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	res = 0;
	va_start(arg_lst, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			res = res + ft_format(&s[i], arg_lst);
		}
		else
			res = res + write(1, &s[i], 1);
		s++;
	}
	va_end (arg_lst);
	return (res);
}

int	main(void)
{
	char *s = "ola";
	ft_printf("%s\n",s);
	printf("%s\n", s);
	return (0);
}