/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 23:53:03 by mlindenm          #+#    #+#             */
/*   Updated: 2022/08/15 20:41:10 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_printf_formatspecifier(const char *formatstring, va_list args)
{
	if (formatstring[0] == 'c')
		return (ft_printf_char((char)va_arg(args, int)));
	else if (formatstring[0] == 's')
		return (ft_printf_string(va_arg(args, char *)));
	else if (formatstring[0] == 'p')
		return (ft_printf_pointer(va_arg(args, unsigned long *)));
	else if (formatstring[0] == 'd')
		return (ft_printf_decimal(va_arg(args, int)));
	else if (formatstring[0] == 'i')
		return (ft_printf_integer(va_arg(args, int)));
	else if (formatstring[0] == 'u')
		return (ft_printf_undecimal(va_arg(args, int)));
	else if (formatstring[0] == 'x')
		return (ft_printf_hexa_low(va_arg(args, int)));
	else if (formatstring[0] == 'X')
		return (ft_printf_hexa_up(va_arg(args, int)));
	else if (formatstring[0] == '%')
	{
		if (write(1, "%", 1))
			return (1);
		else
			return (-1);
	}
	return (0);
}

int	ft_printf(const char *formatstring, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, formatstring);
	while (formatstring[0] != '\0')
	{
		if (formatstring[0] == '%')
		{
			formatstring++;
			count += ft_printf_formatspecifier(formatstring, args);
		}
		else
		{
			if (write(1, formatstring, 1))
				count++;
			else
				return (-1);
		}
		formatstring++;
	}
	va_end(args);
	return (count);
}
