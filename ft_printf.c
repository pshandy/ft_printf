/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:41:07 by pshandy           #+#    #+#             */
/*   Updated: 2021/11/30 14:41:08 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*_ft_printf(char *spec, int *idx, va_list *vlist)
{
	t_props	props;

	spec = get_flags(spec, &props);
	spec = get_width(spec, &props);
	spec = get_precision(spec, &props);
	if (*spec == 'c')
		spec = handle_char(spec, &props, idx, vlist);
	else if (*spec == 's')
		spec = handle_string(spec, &props, idx, vlist);
	else if (*spec == '%')
		spec = handle_percent(spec, idx);
	else if (*spec == 'p')
		spec = handle_pointer(spec, &props, idx, vlist);
	else if (*spec == 'd' || *spec == 'i' || *spec == 'u'
		|| *spec == 'x' || *spec == 'X')
		spec = handle_number(spec, &props, idx, vlist);
	return (spec);
}

int	ft_printf(const char *spec, ...)
{
	int		idx;
	va_list	vlist;

	va_start(vlist, spec);
	idx = 0;
	while (*spec)
	{
		if (*spec != '%')
		{
			ft_putchar(*spec++, idx++);
			continue ;
		}
		else
			spec++;
		spec = _ft_printf((char *)spec, &idx, &vlist);
	}
	va_end(vlist);
	return (idx);
}
