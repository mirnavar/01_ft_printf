/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:16:32 by mirnavar          #+#    #+#             */
/*   Updated: 2022/12/13 15:02:19 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned long long int n);

int	ft_void(unsigned long long int n)
{
	char	*str;
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 3));
	if (!str)
		return (-1);
	str[len + 2] = '\0';
	while (n >= 16)
	{
		str[len - 1] = base[n % 16];
		n = n / 16;
		len--;
	}
	str[len - 1] = base[n % 16];
	str[len - 2] = ft_putstr("0");
	str[len - 3] = ft_putstr("x");
	len = ft_putstr(str) + 2;
	free(str);
	return (len);
}

static int	ft_len(unsigned long long int n)
{
	int	len;

	len = 0;
	while (n >= 16)
	{
		len++;
		n = n / 16;
	}
	len++;
	return (len);
}
