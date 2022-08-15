/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:54:37 by pshandy           #+#    #+#             */
/*   Updated: 2021/11/30 14:54:38 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define FLAGS_ZEROPAD   1 // 1U <<  0U '0'
# define FLAGS_LEFT      2 // 1U <<  1U '-'
# define FLAGS_PLUS      4 // 1U <<  2U '+'
# define FLAGS_SPACE     8 // 1U <<  3U ' '
# define FLAGS_HASH      16 // 1U << 4U '#'
# define FLAGS_PRECISION 32 // 1U << 5U '.'
# define FLAGS_UPPERCASE 64 // 1U << 6U Uppercase

typedef struct s_properties
{
	int	base;
	int	width;
	int	flags;
	int	precision;
	int	spec;
}				t_props;

int		ft_printf(const char *spec, ...);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
void	ft_putchar(char c, int idx);
char	*ft_strdup(const char *s);
char	*_ft_printf(char *spec, int *idx, va_list *vlist);
char	*get_flags(char *spec, t_props *props);
char	*get_width(char *spec, t_props *props);
char	*get_precision(char *spec, t_props *props);
char	*handle_char(char *spec, t_props *props, int *idx, va_list *vlist);
char	*handle_string(char *spec, t_props *props, int *idx, va_list *vlist);
char	*handle_percent(char *spec, int *idx);
char	*handle_pointer(char *spec, t_props *props, int *idx, va_list *vlist);
char	*handle_number(char *spec, t_props *props, int *idx, va_list *vlist);

size_t	ft_strlen(const char *s);
size_t	ft_itoa(unsigned long value, t_props props, int sign, int idx);

#endif
