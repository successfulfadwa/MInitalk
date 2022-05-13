#include"libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1 ;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}
int	hexa_len(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (3);
	while (nb)
	{
		nb = nb / 16;
		len++;
	}
	return (len +2);
}

void	print_hexa_nb(unsigned long int nb, char *base)
{
	if (nb >= 16)
	{
		print_hexa_nb(nb / 16, base);
		print_hexa_nb(nb % 16, base);
	}
	else
	{
		ft_putchar(base[nb]);
	}
}

int	ft_hexax_p(unsigned long int nb, char *base)
{
	ft_putstr("0x");
	print_hexa_nb(nb, base);
	return (hexa_len(nb));
}
int	hexa_len2(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

void	print_hexa_nb1(unsigned int nb, char *base)
{
	if (nb >= 16)
	{
		print_hexa_nb1(nb / 16, base);
		print_hexa_nb1(nb % 16, base);
	}
	if (nb < 16)
	{
		ft_putchar(base[nb]);
	}
}

int	ft_print_x(unsigned int nb, char *base)
{
	print_hexa_nb1(nb, base);
	return (hexa_len2(nb));
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}
unsigned int	ft_nb_len1(unsigned int n)
{
	unsigned int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

unsigned int	ft_putnbr_unsignedint(unsigned int nb)
{
	if (nb > 9)
	{
		ft_putnbr_unsignedint(nb / 10);
	}
	ft_putchar((nb % 10) + 48);
	return (ft_nb_len1(nb));
}
size_t	ft_nb_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr2(int nb)
{
	if (nb == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -1 * nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + 48);
	return (0);
}

int	ft_putnbr(int nb)
{
	ft_putnbr2(nb);
	return (ft_nb_len(nb));
}
int	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		return (ft_putstr("(null)"));
	}
	if (s)
	{
		while (s[i])
		{
			write(1, s + i, 1);
			i++;
		}
	}
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

int	ft_printf_check(va_list list, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	if (c == 'p')
		return (ft_hexax_p(va_arg(list, long int), "0123456789abcdef"));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(list, int)));
	if (c == 'u')
		return (ft_putnbr_unsignedint(va_arg(list, unsigned int)));
	if (c == 'x')
		return (ft_print_x(va_arg(list, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_print_x(va_arg(list, int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	list;

	i = 0;
	len = 0;
	va_start (list, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_printf_check(list, str[i]);
			if (ft_strchr("cspdiuxX%", str[i]) == NULL)
				i--;
		}
		else
			len = len + ft_putchar(str[i]);
		i++;
	}
	va_end (list);
	return (len);
}
