/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zirtaee <zirtaee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:42:02 by zirtaee           #+#    #+#             */
/*   Updated: 2024/11/21 16:40:15 by zirtaee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

# ifndef DECIMAL
#  define DECIMAL "0123456789"
# endif
# ifndef HEXA_UP
#  define HEXA_UP "0123456789ABCDEF"
# endif
# ifndef HEXA_LOW
#  define HEXA_LOW "0123456789abcdef"
# endif

size_t	ft_strlen(const char *s);
int		ft_printf(const char *s, ...);

#endif