/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:23:35 by mlindenm          #+#    #+#             */
/*   Updated: 2022/08/15 15:17:16 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *formatstring, ...);
int	ft_printf_char(char c);
int	ft_printf_string(char *str);
int	ft_printf_pointer(unsigned long *num);
int	ft_printf_decimal(int num);
int	ft_printf_integer(int num);
int	ft_printf_undecimal(unsigned int num);
int	ft_printf_hexa_low(unsigned int num);
int	ft_printf_hexa_up(unsigned int num);

#endif
