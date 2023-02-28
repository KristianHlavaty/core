/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryxaurus <kryxaurus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:12:33 by khlavaty          #+#    #+#             */
/*   Updated: 2023/03/01 00:44:32 by kryxaurus        ###   ########.fr       */
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

int	ft_putbase(long n, char *base, int base_len)
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

int	ft_putnbrbase(long n, char *base)
{
	int	i;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	i = ft_putbase(n, base, base_len);
	return (i);
}

int	ft_puthex(long n, char formt)
{
	if (formt == 'x')
		return (ft_putnbrbase(n, "0123456789abcdef"));
	else
		return (ft_putnbrbase(n, "0123456789ABCDEF"));
}

int	ft_mem(char *mem_c, unsigned long mem)
{
	int	i;

	i = 0;
	while (mem > 0)
	{
		mem_c[i] = mem % 16;
		if (mem_c[i] < 10)
			mem_c[i] += '0';
		else
			mem_c[i] += 87;
		mem = mem / 16;
		i++;
	}
	mem_c[i] = 'x';
	mem_c[i + 1] = '0';
	i++;
	return (i);
}

int	ft_putmemory(unsigned long mem)
{
	char	mem_c[20];
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (mem == 0)
	{
		ft_putstring("(nil)");
		return (5);
	}
	i = ft_mem(&mem_c[0], mem);
	while (i >= 0)
	{
		ft_putchar(mem_c[i]);
		j++;
		i--;
	}
	return (j);
}
