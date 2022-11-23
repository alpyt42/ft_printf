/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:27:48 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/23 10:24:30 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	display_opt(char c, va_list *ap)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(*ap, char));
	if (c == 's')
		i = ft_putstr(va_arg(*ap, char *));
	if (c == 'p')
		i = ft_pointer(va_arg(*ap, int));
	if (c == 'd')
		i = ft_putnbr(va_arg(*ap, int));
	if (c == 'i')
		i = ft_base_ten(va_arg(*ap, int));
	if (c == 'u')
		i = ft_nbr_unsigned(va_arg(*ap, unsigned int));
	if (c == 'x')
		i = ft_hexa_low(va_arg(*ap, int));
	if (c == 'X')
		i = ft_hexa_upp(va_arg(*ap, int));
	if (c == '%')
		i = ft_putchar('%');
	return (i);
}

int opt_list(char c)
{
	char	*optlist;
	int		i;

	optlist = "cspdiuxX%";
	i = 0;
	while (optlist[i])
	{
		if (optlist[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

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
		if (format[i] != '%' && format[i])
			i += ft_putchar(format[i]);
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (opt_list(format[i]) >= 0)
				lentot += display_opt(format[i], ap);
			else if (format[i])
				lentot += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (lentot);
}
