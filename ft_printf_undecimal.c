/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_undecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:49:19 by mlindenm          #+#    #+#             */
/*   Updated: 2022/08/17 16:30:13 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_error(unsigned int nbr)
{
	if (nbr == 0)
	{
		if (write(1, "0", 1))
			return (1);
		else
			return (-1);
	}
	return (0);
}

static int	nbr_length(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static int	print_int_array(unsigned int numbers[], int len)
{
	char	c;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (len > 0)
	{
		c = numbers[i] + '0';
		if (write(1, &c, 1))
		{
			len--;
			i++;
			count++;
		}
		else
			return (-1);
	}
	return (count);
}

int	ft_printf_undecimal(unsigned int num)
{
	unsigned int	temp[10];
	unsigned int	temp_nbr;
	int				i;
	int				count;

	temp_nbr = 0;
	i = 0;
	count = check_error(num);
	if (count == 0)
	{
		temp_nbr = num;
		i = nbr_length(num) - 1;
		while (i >= 0)
		{
			temp[i] = temp_nbr % 10;
			temp_nbr /= 10;
			i--;
		}
		return (count + print_int_array(temp, nbr_length(num)));
	}
	return (count);
}
