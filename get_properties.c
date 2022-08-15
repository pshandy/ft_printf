/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_properties.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:53:18 by pshandy           #+#    #+#             */
/*   Updated: 2021/11/30 14:53:19 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_flags(char *spec, t_props *props)
{
	props->flags = 0;
	while (*spec == '0' || *spec == '-' || *spec == '+' || *spec == ' '
		|| *spec == '#')
	{
		if (*spec == '0')
			props->flags |= FLAGS_ZEROPAD;
		else if (*spec == '-')
			props->flags |= FLAGS_LEFT;
		else if (*spec == '+')
			props->flags |= FLAGS_PLUS;
		else if (*spec == ' ')
			props->flags |= FLAGS_SPACE;
		else if (*spec == '#')
			props->flags |= FLAGS_HASH;
		spec++;
	}
	return (spec);
}

char	*get_width(char *spec, t_props *props)
{
	char	*copy;

	copy = spec;
	props->width = 0;
	if (ft_isdigit(*spec))
	{
		props->width = ft_atoi(spec);
		while (ft_isdigit(*spec))
			spec++;
	}
	return (spec);
}

char	*get_precision(char *spec, t_props *props)
{
	props->precision = 0;
	if (*spec == '.')
	{
		props->flags |= FLAGS_PRECISION;
		spec++;
		if (ft_isdigit(*spec))
			props->precision = ft_atoi(spec);
		else
			props->precision = 0;
		while (ft_isdigit(*spec))
			spec++;
	}
	return (spec);
}
