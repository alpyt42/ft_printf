/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:27:48 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/21 19:36:56 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_eval_conv(format[i + 1]);
		else
			write(1, &format[i++], 1);
	}
}

int	main(void)
{
	printf("%s, %d", "Salut", 2);
}