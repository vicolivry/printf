/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_ws.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 15:44:43 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 17:52:55 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_type_ws_pos(t_format *fmt, wchar_t *str, size_t len, int *ret)
{
	if (!fmt->w && !fmt->p_val)
		while (len)
		{
			len -= wchar_len(*str);
			*ret += ft_putwchar(*str++);
		}
	else if (fmt->w && fmt->p_val)
	{
		*ret += !ft_strcmp((char*)str, "") ? ft_putchar(' ') : 0;
		while (fmt->w-- > len + wchar_len(str[len]) && fmt->w)
			*ret += fmt->zero ? ft_putchar('0') : ft_putchar(' ');
		while (len > 1)
		{
			if (wchar_len(*str) <= len)
				*ret += ft_putwchar(*str);
			str++;
			len -= wchar_len(*str);
		}
	}
	else if (!fmt->w && fmt->p_val)
	{
		while (len > 1)
		{
			if (wchar_len(*str) <= len)
				*ret += ft_putwchar(*str);
			str++;
			len -= wchar_len(*str);
		}
	}
	else if (fmt->w && !fmt->p_val)
	{
		while (fmt->w-- && fmt->w >= len)
			*ret += fmt->zero ? ft_putchar('0') : ft_putchar(' ');
		while (len)
		{
			len -= wchar_len(*str);
			*ret += ft_putwchar(*str++);
		}
	}
}

static void	ft_type_ws_neg(t_format *fmt, wchar_t *str, size_t len, int *ret)
{
	if (!fmt->w_val && !fmt->p_val)
		while (len)
		{
			len -= wchar_len(*str);
			*ret += ft_putwchar(*str++);
		}
	else if (fmt->w && fmt->p_val)
	{
		while (len > 1)
		{
			if (wchar_len(*str) <= len)
				*ret += ft_putwchar(*str);
			str++;
			len -= wchar_len(*str);
		}
		while (fmt->w-- > wstrlen(str) && fmt->w)
			*ret += fmt->zero ? ft_putchar('0') : ft_putchar(' ');
	}
	else if (!fmt->w && fmt->p_val)
		while (len)
		{
			if (wchar_len(*str) <= len)
				*ret += ft_putwchar(*str);
			str++;
			len -= wchar_len(*str);
		}
	else if (fmt->w && !fmt->p_val)
	{
		*ret += !ft_strcmp((char*)str, "") ? ft_putchar(' ') : 0;
	while (len)
		{
			len -= wchar_len(*str);
			fmt->w -= wchar_len(*str);
			*ret += ft_putwchar(*str++);
		}
		while (fmt->w--)
			*ret += ft_putchar(' ');
	}
}

void		ft_type_ws(t_format *fmt, va_list *va, int *ret)
{
	wchar_t		*str;
	int			len;

	str = va_arg(*va, wchar_t*);
	if (!str)
		str = L"(null)";
	len = fmt->p_val && fmt->p <= wstrlen(str) ? fmt->p : wstrlen(str);
	len = fmt->p == 0 && fmt->p_val ? 0 : len;
	if (!fmt->minus)
		ft_type_ws_pos(fmt, str, len, ret);
	else
		ft_type_ws_neg(fmt, str, len, ret);
	*ret += fmt->p_val && fmt->p < wchar_len(str[0]) && fmt->zero ? ft_putchar('0') : 0;
	*ret += fmt->p_val && fmt->p < wchar_len(str[0]) && !fmt->zero ? ft_putchar(' ') : 0;
}
