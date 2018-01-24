/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_s.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 14:06:09 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 19:22:44 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_type_s_wp_pos(t_format *fmt, char *str, size_t len, int *ret)
{
	if (!fmt->w && !fmt->p_val)
		*ret += ft_putstr(str);
	else if (fmt->w && fmt->p_val)
	{
		while (fmt->w-- > len && fmt->w)
			*ret += fmt->zero ? ft_putchar('0') : ft_putchar(' ');
		while (len--)
			*ret += ft_putwchar(*str++);
	}
	else if (!fmt->w && fmt->p_val)
		while (len--)
			*ret += ft_putwchar(*str++);
	else if (fmt->w && !fmt->p_val)
	{
		while (fmt->w-- && fmt->w >= len)
			*ret += fmt->zero ? ft_putchar('0') : ft_putchar(' ');
		while (len--)
			*ret += ft_putwchar(*str++);
	}
}

static void	ft_type_s_wp_neg(t_format *fmt, char *str, size_t len, int *ret)
{
	if (!fmt->w && !fmt->p_val)
		*ret += ft_putstr(str);
	else if (!fmt->w && fmt->p_val)
		while (len--)
			*ret += ft_putwchar(*str++);
	else if (fmt->w && fmt->p_val)
	{
		while (len--)
		{
			*ret += ft_putwchar(*str++);
			fmt->w--;
		}
		while (fmt->w--)
			*ret += ft_putchar(' ');
	}
	else if (fmt->w && !fmt->p_val)
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

	str = (char*)varg;
	if (varg == (long)NULL)
		str = ("null");
	len = fmt->p_val && fmt->p <= ft_strlen(str) ? fmt->p : ft_strlen(str);
	len = fmt->p == 0 && fmt->p_val ? 0 : len;
	if (!fmt->minus)
		ft_type_s_wp_pos(fmt, str, len, ret);
	else
		ft_type_s_wp_neg(fmt, str, len, ret);
}
