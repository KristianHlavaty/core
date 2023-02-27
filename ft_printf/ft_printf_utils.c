/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:12:33 by khlavaty          #+#    #+#             */
/*   Updated: 2023/02/27 18:35:22 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstring(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		str = "(null)";
	}
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		i;
	char	c;

	c = 0;
	i = 0;
	if (n == -2147483648)
	{
		i += ft_putstring("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	if (n < 10 && n != -2147483648)
	{
		c = n + '0';
		i += ft_putchar(c);
	}
	return (i);
}

int	ft_putnbrunsig(unsigned int n)
{
	char	c;
	int		i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbrunsig(n / 10);
		i += ft_putnbrunsig(n % 10);
	}
	if (n < 10)
	{
		c = n + '0';
		i += ft_putchar(c);
	}
	return (i);
}

int	ft_putbase(int n, char *base, int base_len)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		ft_putchar('-');
		i++;
		n = n * (-1);
	}
	if (n / base_len > 0)
	{
		i = i + ft_putbase(n / base_len, base, base_len);
	}
	ft_putchar(base[n % base_len]);
	return (i);
}

int	ft_putnbrbase(int n, char *base)
{
	int	i;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	i = ft_putbase(n, base, base_len);
	return (i);
}

int	ft_puthex(unsigned int n, char formt)
{
	if (formt == 'x')
		return (ft_putnbrbase(n, "0123456789abcdef"));
	else
		return (ft_putnbrbase(n, "0123456789ABCDEF"));
}
