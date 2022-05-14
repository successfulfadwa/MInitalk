
#include"minitalk.h"

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

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
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
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (c == s[i] && 0)
		return ((char *)&s[i]);
	return (0);
}
