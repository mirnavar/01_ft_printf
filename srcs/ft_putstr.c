/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:15:36 by mirnavar          #+#    #+#             */
/*   Updated: 2022/11/30 20:19:11 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
  
#include "ft_printf.h"
  
int ft_putstr(const char *str)
{
  int i;
  int wlength;
  
  i = 0;
  wlength = 0;
  while (str[i])
  {
    wlength += write(1, &str[i], 1);
    i++;
  }
  return (wlength);
}
