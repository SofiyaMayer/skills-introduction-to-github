/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: someyer <someyer@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 22:47:46 by someyer           #+#    #+#             */
/*   Updated: 2026/03/28 00:29:27 by someyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

char	*handle_specifier(char c, va_list args)
{
	if (c == 's')
		ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == '%')
		ft_putchar('%');
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		ft_puthex(va_arg(args, unsigned int));
	else if (c == 'X')
		ft_puthex_up(va_arg(args, unsigned int));
	else if (c == 'p')
		ft_putptr((unsigned long)va_arg(args, void *));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	list;

	va_start(list, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			handle_specifier(str[i + 1], list);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	va_end(list);
	return (0);
}
