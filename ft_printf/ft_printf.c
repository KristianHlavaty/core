/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:12:11 by khlavaty          #+#    #+#             */
/*   Updated: 2023/02/25 23:16:23 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fts_check_formt(va_list args, char formt)
{
	if (formt == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (formt == 's')
		return (ft_putstring(va_arg(args, char *)));
	else if (formt == 'i' || formt == 'd')
		return (ft_putnbr(va_arg(args, int)));
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
		if (input[i] == '%')
		{
			len += fts_check_formt(args, input[i + 1]);
			i++;
		}
		else
			len += ft_putchar(input[i]);
		i++;
	}
	va_end(args);
	return (len);
}
