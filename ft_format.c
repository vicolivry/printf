/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_format.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:32:41 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 10:55:40 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	ft_format_flags(const char **str, t_format *format)
{
	if (**str == '+')
		format->plus = 1;
	if (**str == '-')
		format->minus = 1;
	if (**str == '#')
		format->hash = 1;
	if (**str == ' ')
		format->space = 1;
	if (**str == '0')
		format->zero = 1;
	*str = *str + 1;
}

void	ft_format_length(const char **str, t_format *format)
{
	format->l = **str;
	if (**str == 'l')
	{
		*str = *str + 1;
		if (**str == 'l')
			format->l = 'L';
		else
			*str = *str - 1;
	}
	if (**str == 'h')
	{
		*str = *str + 1;
		if (**str == 'h')
			format->l = 'H';
		else
			*str = *str - 1;
	}
	*str = *str + 1;
}

void	ft_format_precis(const char **str, t_format *format)
{
	int	precis;

	precis = 0;
	*str = *str + 1;
	if (format->p)
		format->p = 0;
	while (ft_isdigit(**str))
	{
		precis = precis * 10 + (**str - '0');
		*str = *str + 1;
	}
	format->p = precis;
	format->p_val = 1;
}

void	ft_format_width(const char **str, t_format *format)
{
	int	width;

	width = 0;
	if (format->w)
		format->w = 0;
	while (ft_isdigit(**str))
	{
		width = width * 10 + (**str - '0');
		*str = *str + 1;
	}
	format->w = width;
	format->w_val = 1;
}
