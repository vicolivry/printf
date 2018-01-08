/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_format.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 15:32:41 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 18:20:25 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	ft_format_flags(char **str, t_format *format, int i)
{
	format->flags[i] = **str;
	*str = *str + 1;
}

void	ft_format_length(char **str, t_format *format)
{
	format->length = **str;
	if (**str == 'l')
	{
		*str = *str + 1;
		if (**str == 'l')
		format->length = 'L';
	}
	if (**str == 'h')
	{
		*str = *str + 1;
		if (**str == 'h')
		format->length = 'H';
	}
	*str = *str + 1;
}

void	ft_format_precis(char **str, t_format *format)
{
	int	precis;

	precis = 0;
	*str = *str + 1;
	if (format->precis)
		format->precis = 0;
	while (ft_isdigit(**str))
	{
		precis = precis * 10 + (**str - '0');
		*str = *str + 1;
	}
	format->precis = precis;
}

void	ft_format_width(char **str, t_format *format)
{
	int	width;

	width = 0;
	if (format->width)
		format->width = 0;
	while (ft_isdigit(**str))
	{
		width = width * 10 + (**str - '0');
		*str = *str + 1;
	}
	format->width = width;
}
