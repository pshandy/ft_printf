/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:04:55 by pshandy           #+#    #+#             */
/*   Updated: 2021/11/30 15:32:13 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	format(t_props props, char *buf, int len, int sign);
size_t	reverse_print(t_props props, char *buf, int len, int idx);

size_t	ft_itoa(unsigned long value, t_props props, int sign, int idx)
{
	size_t	len;
	int		digit;
	char	buff[64];

	len = 0;
	if (value == 0)
	{
		if (!((props.flags & FLAGS_PRECISION) && props.precision == 0))
			buff[len++] = '0';
		sign = 1;
	}
	while (value != 0)
	{
		digit = value % props.base;
		if (digit < 10)
			buff[len++] = '0' + digit;
		else if (props.flags & FLAGS_UPPERCASE)
			buff[len++] = 'A' + digit - 10;
		else
			buff[len++] = 'a' + digit - 10;
		value /= props.base;
	}
	buff[len] = '\0';
	return (format(props, buff, idx, sign));
}

char	*print_hash(t_props props, char *buf, int *len)
{
	if (!(props.flags & FLAGS_PRECISION) && len
		&& !(buf[0] == '0' && buf[1] == '\0' && props.spec != 'p'))
	{
		if ((props.base == 16) && !(props.flags & FLAGS_UPPERCASE))
			buf[(*len)++] = 'x';
		else if ((props.base == 16) && (props.flags & FLAGS_UPPERCASE))
			buf[(*len)++] = 'X';
		else if (props.base == 2)
			buf[(*len)++] = 'b';
		buf[(*len)++] = '0';
	}
	return (buf);
}

size_t	format(t_props props, char *buf, int idx, int sign)
{
	int	len;

	len = ft_strlen(buf);
	if (!(props.flags & FLAGS_LEFT))
	{
		while ((len < props.precision))
			buf[len++] = '0';
		if ((props.flags & FLAGS_ZEROPAD) && sign == 0)
			props.width--;
		while ((props.flags & FLAGS_ZEROPAD) && (len < props.width))
			buf[len++] = '0';
	}
	else
		while ((len < props.precision))
			buf[len++] = '0';
	if (props.flags & FLAGS_HASH)
		buf = print_hash(props, buf, &len);
	if (sign == 0)
		buf[len++] = '-';
	else if (props.flags & FLAGS_PLUS)
		buf[len++] = '+';
	else if (props.flags & FLAGS_SPACE)
		buf[len++] = ' ';
	return (reverse_print(props, buf, len, idx));
}

size_t	reverse_print(t_props props, char *buf, int len, int idx)
{
	int	start_idx;
	int	i;

	i = len;
	start_idx = idx;
	if (!(props.flags & FLAGS_LEFT)
		&& !(props.flags & FLAGS_ZEROPAD) && props.width)
		while (i++ < props.width)
			ft_putchar(' ', idx++);
	while (len)
		ft_putchar(buf[--len], idx++);
	if (props.flags & FLAGS_LEFT)
		while (idx - start_idx < props.width)
			ft_putchar(' ', idx++);
	return (idx);
}
