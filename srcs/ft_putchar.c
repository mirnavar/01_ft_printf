/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:02:39 by mirnavar          #+#    #+#             */
/*   Updated: 2022/11/29 16:23:30 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putchar(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}
/*el write devuelve un ssize_t indicando el numero de 
 * caracteres que ha escrito. En este caso, como es un char solo 
 * char lo que le enviamos, tiene que devolver 
 * error si ssize_t es diff a 1*/
