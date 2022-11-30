HEADER!!!
  
#include "ft_printf.h"
  
int ft_putstr(const char *str)
{
  int i;
  int strlen;
  
  i = 0;
  wlength = 0;
  while (str[i])
  {
    wlength += write(1, &str[i], 1);
    i++;
  }
  return (wlength),
}
