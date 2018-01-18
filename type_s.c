/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_s.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 14:06:09 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/18 14:56:48 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_type_s_wp_pos(t_format *fmt, char *str, size_t len, int *ret)
{
	str = (fmt->t == 's' && fmt->l != 'l') ? (char*)str : str;
	if (fmt->w && fmt->p)
	{
		while (fmt->w-- > len && fmt->w)
			*ret += ft_strchr(fmt->f, '0') ? ft_putchar('0') : ft_putchar(' ');
		*ret += ft_putstr(str);
	}
	else if (!fmt->w && fmt->p >= 0)
	{
		while (len--)
			*ret += ft_putwchar(*str++);
	}
	else if (fmt->w && fmt->p >= 0)
	{
		while (fmt->w-- && fmt->w >= len)
			*ret += ft_strchr(fmt->f, '0') ? ft_putchar('0') : ft_putchar(' ');
		while (len--)
			*ret += ft_putwchar(*str++);
	}
}

static void	ft_type_s_wp_neg(t_format *fmt, char *str, size_t len, int *ret)
{
	str = (fmt->t == 's' && fmt->l != 'l') ? (char*)str : str;
	if (!fmt->w && fmt->p)
	{
		while (len--)
			*ret += ft_putwchar(*str++);
	}
	else if (fmt->w && fmt->p >= 0)
	{
		while (len--)
			*ret += ft_putwchar(*str++);
		while (fmt->w-- && fmt->w >= fmt->p)
			*ret += ft_putchar(' ');
	}
	else if (fmt->w && !fmt->p)
	{
		*ret += ft_putstr(str);
		while (fmt->w-- > len && fmt->w)
			*ret += ft_putchar(' ');
	}
}

void		ft_type_s(t_format *fmt, intmax_t varg, int *ret)
{
	char	*str;
	size_t	len;

	str = (wchar_t*)varg;
	len = fmt->p && fmt->p <= ft_strlen(str) ? fmt->p : ft_strlen(str);
	len = fmt->p == 0 ? 0 : len;
	if (!ft_strchr(fmt->f, '-'))
		ft_type_s_wp_pos(fmt, str, len, ret);
	else
		ft_type_s_wp_neg(fmt, str, len, ret);
}
