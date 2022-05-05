/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:08:42 by gkitoko           #+#    #+#             */
/*   Updated: 2022/02/09 20:58:09 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_somethin(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_puthexamem(va_arg(args, unsigned long int));
	}
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'x')
		count += ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
	{
		count++;
		write(1, "%", 1);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += print_somethin(str[i + 1], args);
			if (str[i + 1] == 'i')
				count += ft_putnbr(va_arg(args, int));
			else if (str[i +1] == 'u')
				count += ft_putnbr(va_arg(args, unsigned int));
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
