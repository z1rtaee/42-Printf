/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-r <bpires-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:11:28 by bpires-r          #+#    #+#             */
/*   Updated: 2024/11/20 20:18:17 by bpires-r         ###   ########.fr       */
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
	{
		res = res + ft_putnbr(n / base, base, base_str);
		c = '0' + (n % base);
		res = res + write(1, &c, 1);
	}
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
	// else if (*s == 'p')
	// 	re = res + 
	return (res);
}
int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	arg_lst;

	res = 0;
	va_start(arg_lst, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			res = res + ft_format(&*s, arg_lst);
		}
		else
			write(1, &*s, 1);
		s++;
	}
	return (res);
}

// int	zt_putptr(void *p)
// {
// 	unsigned long ptr;

// 	ptr = (unsigned long)p
// 	if (!ptr)
// 		return (zt_putstr("(nil)"));
	
// }

int main()
{
	ft_printf("%d",234);
}