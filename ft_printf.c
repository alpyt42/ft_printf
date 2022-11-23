/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:27:48 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/23 13:14:05 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display_opt(char c, va_list *ap)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(*ap, int));
	if (c == 's')
		i = ft_putstr(va_arg(*ap, char *));
	if (c == 'p')
	{
		i += ft_putstr("0x");
		i += ft_putnbr_uns(va_arg(*ap, unsigned int),"0123456789abcdef");
	}
	if (c == 'd' || c == 'i')
		i = ft_putnbr_int(va_arg(*ap, int), "0123456789");
	if (c == 'u')
		i = ft_putnbr_uns(va_arg(*ap, unsigned int), "0123456789");
	if (c == 'x')
		i = ft_putnbr_uns(va_arg(*ap, unsigned int), "0123456789abcdef");
	if (c == 'X')
		i = ft_putnbr_uns(va_arg(*ap, unsigned int), "0123456789ABCDEF");
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
			lentot += ft_putchar(format[i]);
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (opt_list(format[i]) >= 0)
				lentot += display_opt(format[i], &ap);
			else if (format[i])
				lentot += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (lentot);
}

// int	main(void)
// {
// 	char	*c;
// 	char	t;
// 	int		d;
// 	int		gg;
// 	c = "prout";
// 	t = 'e';
// 	gg = 123;
// 	// d = ft_printf("c%sallo%c%X", c, t, gg);
// 	d = ft_printf(" NULL %s NULL ", NULL);
// 	printf("%d\n", d);
// 	gg = printf(" NULL %s NULL ", NULL);
// 	printf("%d", gg);
// 	// printf("%d", d);
// }
