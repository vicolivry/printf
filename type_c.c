/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_c.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 13:21:29 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 14:42:26 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_width_unicode(t_format *fmt, intmax_t varg)
{
	if (varg <= 0x7FF && varg >= 0x7F)
		fmt->width--;
	else if (varg <= 0xFFFF && varg >= 0x7F)
		fmt->width -= 2;
	else if (varg <= 0x1FFFFF && varg >= 0x7F)
		fmt->width -= 3;
}

void		ft_type_c(t_format *fmt, intmax_t varg, int *ret)
{
	varg = fmt->type == 'C' || fmt->length == 'l' ? (wchar_t)varg : (char)varg;
	varg = fmt->type == '%' ? 37 : varg;
	ft_width_unicode(fmt, varg);
	*ret += ft_strchr(fmt->flags, '-') ? ft_putwchar(varg) : 0;
	while (fmt->width-- > 1)
		*ret += ft_putchar(' ');
	*ret += !ft_strchr(fmt->flags, '-') ? ft_putwchar(varg) : 0;
}
