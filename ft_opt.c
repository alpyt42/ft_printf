/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-cont <ale-cont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:16:01 by ale-cont          #+#    #+#             */
/*   Updated: 2022/11/22 19:01:46 by ale-cont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int	is_opt(const char *format, va_list *ap, size_t *i, size_t *lentot)
{
	if (opt_list(format[*i + 1] >= 0))
	{
		display_option(format, &ap, &i, &lentot);
		return (1);
	}
	else
		return (0);
}

check_opt(const char *format, va_list *ap, size_t *i, size_t *lentot)
{
	if (!is_opt(format, ap, i, lentot))
		i += 1;
	if (format[*i] == '\0')
	{
		va_end(*ap);
		return (*lentot);
	}
	return (0);
}