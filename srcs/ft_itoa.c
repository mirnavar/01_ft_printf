
#include "ft_printf.h"

static void	ft_len(int n, int *len);

int	ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
		return (11);
	ft_len(n, &len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	//if (!str)
	//	return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 9)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	str[len - 1] = (n % 10) + 48;
//	ft_putstr(str);
	return (len); //hace falta que devuelva aqui len? en realidad, si llamo a la funcion ft_putstr
					// ella misma ya devuelve el numero de caract. printeados, no?
}

static void	ft_len(int n, int *len)
{
	int	i;

	*len = 0;
	i = 0;
	if (n < 0)
	{
		i++;
		*len += 1;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		*len += 1;
	}
	if (n >= 0)
		*len += 1;
}
