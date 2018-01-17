/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_c.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 13:21:29 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 17:13:45 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_width_unicode(t_format *fmt, intmax_t varg)
{
	if (varg <= 0x7FF && varg >= 0x7F)
		fmt->w--;
	else if (varg <= 0xFFFF && varg >= 0x7F)
		fmt->w -= 2;
	else if (varg <= 0x1FFFFF && varg >= 0x7F)
		fmt->w -= 3;
}

void		ft_type_c(t_format *fmt, intmax_t varg, int *ret)
{
	varg = fmt->t == 'C' || fmt->l == 'l' ? (wchar_t)varg : (char)varg;
	varg = fmt->t == '%' ? 37 : varg;
	ft_width_unicode(fmt, varg);
	*ret += ft_strchr(fmt->f, '-') ? ft_putwchar(varg) : 0;
	while (fmt->w-- > 1)
		*ret += ft_putchar(' ');
	*ret += !ft_strchr(fmt->f, '-') ? ft_putwchar(varg) : 0;
}
