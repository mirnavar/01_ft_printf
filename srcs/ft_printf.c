/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:55:05 by mirnavar          #+#    #+#             */
/*   Updated: 2022/12/01 16:16:58 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (str[i] == 'c')
				rslt += ft_putchar(va_arg(args, int));
			if (str[i] == 's')
				rslt += ft_putstr(va_arg(args, const char *));
		}
		else
			rslt += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (rslt);
}

int ft_conversion(const char *str, va_list args)
{

}
