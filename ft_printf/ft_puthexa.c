/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:42:54 by gkitoko           #+#    #+#             */
/*   Updated: 2022/02/09 20:34:15 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthexa(unsigned int num, char *base)
{
	int	count;

	count = 0;
	if (num > 15)
		count += ft_puthexa(num / 16, base);
	count += ft_putchar(base[num % 16]);
	return (count);
}
