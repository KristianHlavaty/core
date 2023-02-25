/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:12:11 by khlavaty          #+#    #+#             */
/*   Updated: 2023/02/25 16:55:04 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fts_check_formt(va_list args, char formt)
{
	if (formt == 'c')
		return (ft_putchar_fd(va_arg(args, int)));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, input);
	while (input[i])
	{
		if (str[i] == '%')
		{
			len += fts_check_formt(args, input[i + 1]);
			i++;
		}
		else
			len += ft_putchar_fd(input[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	char	*arr;
	int	n, res1, res2;
	char	c;
	unsigned int	p;
	arr = " fghjghj se 235y: dr`";
 	n = -2647678;
	c = 'D';
	p  = 234;
	res1 = ft_printf("%s", arr);
	res2 = printf("%s", arr);
	res1 = ft_printf("deci prosim  %d\t \n", n);
	res2 = printf("deci prosim  %d\t \n", n);
	res1 = ft_printf("chacha %c\n", c);
	res2 = printf("chacha %c\n", c);
	res1 = ft_printf("int %i\n", n);
	res2 = printf("int %i\n", n);
	res1 = ft_printf("unsigned %u\n", p);
	res2 = printf("unsigned %u\n", p);
	res1 = ft_printf("hex %X\n", p);
	res2 = printf("hex %X\n", p);
	res1 = ft_printf("hexaaaaaaaaaaa %x\n", p);
	res2 = printf("hexaaaaaaaaaaa %x\n", p);
	res1 = ft_printf("percent %%\n");
	res2 = printf("percent %%\n");
	res1 = ft_printf("void*: %p %p\n", 0, 0);
	res2 = printf("void*: %p %p\n", 0, 0);
	printf ("%i - %i\n", res1, res2);
}
