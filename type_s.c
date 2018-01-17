/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_s.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 14:06:09 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 17:24:33 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_type_s_wp_pos(t_format *fmt, char *str, size_t len, int *ret)
{
	str = (fmt->t == 's' && fmt->l != 'l') ? (char*)str : str;
	if (fmt->w && !fmt->p)
	{
		while (fmt->w-- > ft_strlen(str) && fmt->w)
			*ret += ft_putchar(' ');
	}
	else if (!fmt->w && fmt->p)
	{
		while (fmt->p-- > len && fmt->p)
			*ret += ft_putwchar(*str++);
	}
	else if (fmt->w && fmt->p)
	{
		fmt->p = fmt->p >= len ? len : fmt->p;
		while (fmt->w-- && fmt->w >= fmt->p)
			*ret += ft_putchar(' ');
		while (fmt->p--)
			*ret += ft_putwchar(*str++);
	}
}

static void	ft_type_s_wp_neg(t_format *fmt, char *str, size_t len, int *ret)
{
	str = (fmt->t == 's' && fmt->l != 'l') ? (char*)str : str;
	if (!fmt->w && fmt->p)
	{
		while (fmt->p-- > len && fmt->p)
			*ret += ft_putwchar(*str++);
	}
	else if (fmt->w && fmt->p)
	{
		fmt->p = fmt->p >= len ? len : fmt->p;
		while (fmt->p--)
		{
			*ret += ft_putwchar(*str++);
			fmt->w--;
		}
		while (fmt->w-- && fmt->w >= fmt->p)
			*ret += ft_putchar(' ');
	}
	else if (fmt->w && !fmt->p)
	{
		while (len--)
			*ret += ft_putwchar(*str++);
		while (fmt->w-- > ft_strlen(str) && fmt->w)
			*ret += ft_putchar(' ');
	}
}

void		ft_type_s(t_format *fmt, intmax_t varg, int *ret)
{
	char	*str;
	size_t	len;

	str = (wchar_t*)varg;
	len = ft_strlen(str);
	if (!ft_strchr(fmt->f, '-'))
		ft_type_s_wp_pos(fmt, str, len, ret);
	else
		ft_type_s_wp_neg(fmt, str, len, ret);
}
