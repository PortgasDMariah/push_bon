/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:17:45 by mdouiri           #+#    #+#             */
/*   Updated: 2022/04/21 22:22:40 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "struct.h"
#include <stdarg.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!(str))
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_putnbr(long int n, char *base, int *count)
{
	int	leni;

	leni = ft_strleni(base);
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		(*count)++;
	}
	if (n >= leni)
	{
		ft_putnbr((n / leni), base, count);
		ft_putnbr((n % leni), base, count);
	}
	else
	{
		(*count)++;
		ft_putchar(base[n % leni]);
	}
}

void	ft_putnbri(unsigned long int n, char *base, int *count)
{
	unsigned long int	leni;

	leni = ft_strleni(base);
	if (n >= leni)
	{
		ft_putnbri((n / leni), base, count);
		ft_putnbri((n % leni), base, count);
	}
	else
	{
		(*count)++;
		ft_putchar(base[n % leni]);
	}
}

void	ft_what(const char m, va_list va, int *count)
{
	if (m == 'd' || m == 'i')
		ft_putnbr(va_arg(va, int), "0123456789", count);
	else if (m == 'u')
		ft_putnbri(va_arg(va, unsigned int), "0123456789", count);
	else if (m == 'c')
		*count += ft_putchar(va_arg (va, int));
	else if (m == 'X')
		ft_putnbr(va_arg(va, unsigned int), "0123456789ABCDEF", count);
	else if (m == 'x')
		ft_putnbr(va_arg (va, unsigned int), "0123456789abcdef", count);
	else if (m == 's')
		*count += ft_putstr(va_arg (va, char *));
	else if (m == '%')
		*count += ft_putchar('%');
	else if (m == 'p')
	{
		*count += ft_putstr("0x");
		ft_putnbri(va_arg (va, unsigned long int), "0123456789abcdef", count);
	}
}

int	ft_printf(char *bon, ...)
{
	va_list	va;
	int		count;
	int		i;

	va_start(va, bon);
	i = 0;
	count = 0;
	while (bon[i])
	{
		if (bon[i] == '%')
		{
			i++;
			ft_what(bon[i], va, &count);
		}
		else
		{
			count++;
			write(1, &bon[i], 1);
		}
		i++;
	}
	va_end(va);
	return (count);
}
