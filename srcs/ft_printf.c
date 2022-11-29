/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:55:05 by mirnavar          #+#    #+#             */
/*   Updated: 2022/11/29 16:25:24 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	ssize_t	rslt;

	va_start(args, str);
	i = 0;
	while (*str)
	{
		while (str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
		}
		if (str[i + 1] == 'c')
			rslt = ft_putchar(va_arg(args, int));
	}
	va_end(args);
	return (rslt);
}
