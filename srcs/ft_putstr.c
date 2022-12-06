/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:15:36 by mirnavar          #+#    #+#             */
/*   Updated: 2022/12/05 14:23:01 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	wlength;

	if (!str)
		str = "(null)";
	i = 0;
	wlength = 0;
	while (str[i])
	{
		wlength += write(1, &str[i], 1);
		i++;
	}
//	printf("valor devuelto por ft_putstr %d\n", wlength);
	return (wlength);
}
