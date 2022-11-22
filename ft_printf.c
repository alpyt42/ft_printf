/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:27:48 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/22 19:01:48 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	lentot;
	va_list	ap;

	i = 0;
	lentot = 0;
	va_start(ap, format);
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (check_opt(format, &ap, &i, &lentot))
				return (lentot);
		}
		if (format[i] != '\0' && format[i])
			lentot += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (lentot);
}
