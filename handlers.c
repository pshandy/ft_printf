/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:53:30 by pshandy           #+#    #+#             */
/*   Updated: 2021/11/30 14:53:31 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*handle_char(char *spec, t_props *props, int *idx, va_list *vlist)
{
	int	l;

	l = 1;
	if (!(props->flags & FLAGS_LEFT))
		while (l++ < props->width)
			ft_putchar(' ', (*idx)++);
	ft_putchar(va_arg(*vlist, int), (*idx)++);
	if (props->flags & FLAGS_LEFT)
		while (l++ < props->width)
			ft_putchar(' ', (*idx)++);
	return (++spec);
}

char	*handle_string(char *spec, t_props *props, int *idx, va_list *vlist)
{
	const char	*p;
	char		*null;
	int			l;

	null = ft_strdup("(null)");
	p = va_arg(*vlist, char *);
	if (p == NULL)
		p = null;
	l = ft_strlen(p);
	if (props->flags & FLAGS_PRECISION)
		if (l >= props->precision)
			l = props->precision;
	if (!(props->flags & FLAGS_LEFT))
		while (l++ < props->width)
			ft_putchar(' ', (*idx)++);
	if (p != NULL)
		while ((*p != 0) && (!(props->flags & FLAGS_PRECISION)
				|| props->precision--))
			ft_putchar(*(p++), (*idx)++);
	spec++;
	if (props->flags & FLAGS_LEFT)
		while (l++ < props->width)
			ft_putchar(' ', (*idx)++);
	free(null);
	return (spec);
}

char	*handle_percent(char *spec, int *idx)
{
	ft_putchar('%', (*idx)++);
	return (++spec);
}

char	*handle_pointer(char *spec, t_props *props, int *idx, va_list *vlist)
{
	unsigned long	value;

	props->spec = 'p';
	value = (unsigned long) va_arg(*vlist, void *);
	if (!props->width)
		props->width = 0;
	props->flags |= FLAGS_HASH;
	props->base = 16;
	*idx = ft_itoa(value, *props, value > 0, *idx);
	return (++spec);
}
