/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:16:34 by gkitoko           #+#    #+#             */
/*   Updated: 2022/02/09 20:34:52 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_int(long int n)
{
	int	res;

	res = 0;
	while (n > 9)
	{
		n = n / 10;
		if (n < 9 && n <= 0)
			res++;
		res++;
	}
	return (res);
}

int	ft_putnbr(long int n)
{
	int			count;
	long int	num;

	count = 0;
	if (n == -2147483648)
		return (count += ft_putstr("-2147483648"));
	num = n;
	if (num < 0)
	{
		num *= -1;
		count += ft_putchar('-');
	}
	count += len_int(num);
	if (num > 9)
	{
		ft_putnbr(num / 10);
	}
	count += ft_putchar(num % 10 + 48);
	return (count);
}
