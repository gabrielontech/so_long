/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexamem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:04:39 by gkitoko           #+#    #+#             */
/*   Updated: 2022/02/09 20:14:58 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexamem(unsigned long int num)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (num == 0)
	{
		return (count += ft_putstr("0"));
	}
	if (num > 15)
		count += ft_puthexamem(num / 16);
	count += ft_putchar(base[num % 16]);
	return (count);
}
