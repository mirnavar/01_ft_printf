/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:55:05 by mirnavar          #+#    #+#             */
/*   Updated: 2022/12/02 12:43:33 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_conversion(va_list args, char conver);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		rslt;

	va_start(args, str);
	i = 0;
	rslt = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				rslt += write(1, "%", 1);
			else
				rslt += ft_conversion(args, str[i]);
		}
		else
			rslt += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (rslt);
}

static int ft_conversion(va_list args, char conver)
{
	int	rslt;

	rslt = 0;
	if (conver == 'c')
		rslt += ft_putchar(va_arg(args, int));
	else if (conver == 's')
		rslt += ft_putstr(va_arg(args, char *));
	else if (conver == 'd')
		rslt += ft_itoa(va_arg(args, int));
	return (rslt);
}
