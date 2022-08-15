/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:55:03 by pshandy           #+#    #+#             */
/*   Updated: 2021/11/30 14:55:05 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	handle_signed(t_props *props, int *idx, va_list *vlist)
{
	long int	value;

	value = va_arg(*vlist, int);
	if (value >= 0)
		*idx = ft_itoa(value, *props, value > 0, *idx);
	else
		*idx = ft_itoa(-value, *props, value > 0, *idx);
}

static void	handle_unsigned(t_props *props, int *idx, va_list *vlist)
{
	unsigned int	value;

	value = va_arg(*vlist, unsigned int);
	*idx = ft_itoa(value, *props, value > 0, *idx);
}

char	*handle_number(char *spec, t_props *props, int *idx, va_list *vlist)
{
	if (*spec == 'x' || *spec == 'X')
		props->base = 16;
	else
	{
		props->base = 10;
		props->flags &= ~FLAGS_HASH;
	}
	if (*spec == 'X')
		props->flags |= FLAGS_UPPERCASE;
	if ((*spec != 'i') && (*spec != 'd'))
		props->flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
	if (props->flags & FLAGS_PRECISION)
		props->flags &= ~FLAGS_ZEROPAD;
	if ((*spec == 'i') || (*spec == 'd'))
		handle_signed(props, idx, vlist);
	else
		handle_unsigned(props, idx, vlist);
	return (++spec);
}
