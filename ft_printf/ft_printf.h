/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryxaurus <kryxaurus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:11:09 by khlavaty          #+#    #+#             */
/*   Updated: 2023/03/01 00:34:13 by kryxaurus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *input, ...);
int		ft_putchar(char c);
int		fts_check_formt(va_list args, char formt);
int		ft_putstring(char *str);
int		ft_putnbr(int n);
int		ft_putnbrunsig(unsigned int n);
int		ft_puthex(long n, char formt);
size_t	ft_strlen(const char *str);
int		ft_putbase(long n, char *base, int base_len);
int		ft_putnbrbase(long n, char *base);
int		ft_mem(char *mem_c, unsigned long mem);
int		ft_putmemory(unsigned long mem);

#endif