/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_ws.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 15:44:43 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 16:23:47 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static int	wchar_len(wchar_t c)
{
	int	len;

	len = 1;
	if (c <= 0x7FF && c >= 0x7F)
		len = 2;
	else if (c <= 0xFFFF && c >= 0x7F)
		len = 3;
	else if (c <= 0x1FFFFF && c >= 0x7F)
		len = 4;
	return (len);
}

static int	wstrlen(wchar_t *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += wchar_len(str[i]);
		i++;
	}
	return (len);
}

static void	ft_type_ws_pos(t_format *fmt, char *str, size_t len, int *ret)
{
	int	length;

	length = wstrlen((wchar_t*)str);
	if (!fmt->w && !fmt->p_val)
		while(length--)
			ft_printf("%C", (wchar_t)*str++);
	else if (fmt->w && fmt->p_val)
	{
		*ret += !ft_strcmp(str, "") ? ft_putchar(' ') : 0;
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

static void	ft_type_ws_neg(t_format *fmt, char *str, size_t len, int *ret)
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
		*ret += !ft_strcmp(str, "") ? ft_putchar(' ') : 0;
		*ret += ft_putstr(str);
		while (fmt->w-- > len && fmt->w)
			*ret += ft_putchar(' ');
	}
}


void	ft_type_ws(t_format *fmt, va_list *va, int *ret)
{
	char		*str;
	size_t		len;
	uintmax_t	varg;

	str = va_arg(*va, char*);
	if (str == (NULL))
		str = ("(null)");
	len = fmt->p_val && fmt->p <= ft_strlen(str) ? fmt->p : ft_strlen(str);
	len = fmt->p == 0 && fmt->p_val ? 0 : len;
	if (!fmt->minus)
		ft_type_ws_pos(fmt, str, len, ret);
	else
		ft_type_ws_neg(fmt, str, len, ret);
	*ret += fmt->p_val && fmt->p <= 0 && fmt->zero ? ft_putchar('0') : 0;
	*ret += fmt->p_val && fmt->p <= 0 && !fmt->zero ? ft_putchar(' ') : 0;
}
