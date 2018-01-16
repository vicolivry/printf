/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_s.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/16 14:06:09 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 18:05:39 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_type_s_wp_pos(t_format *fmt, char *str, size_t len, int *ret)
{
	str = (fmt->type == 's' && fmt->length != 'l') ? (char*)str : str;
	if (fmt->width && !fmt->precis)
	{
		while (fmt->width-- > ft_strlen(str) && fmt->width)
			*ret += ft_putchar(' ');
	}
	else if (!fmt->width && fmt->precis)
	{
		while (fmt->precis-- > len  && fmt->precis)
			*ret += ft_putwchar(*str++);
	}
	else if (fmt->width && fmt->precis)
	{
		fmt->precis = fmt->precis >= len ? len : fmt->precis;
		while (fmt->width-- && fmt->width >= fmt->precis)
			*ret += ft_putchar(' ');
		while (fmt->precis--)
			*ret += ft_putwchar(*str++);
	}
}

static void	ft_type_s_wp_neg(t_format *fmt, char *str, size_t len, int *ret)
{
	str = (fmt->type == 's' && fmt->length!= 'l') ? (char*)str : str;
	if (!fmt->width && fmt->precis)
	{
		while (fmt->precis-- > len  && fmt->precis)
			*ret += ft_putwchar(*str++);
	}
	else if (fmt->width && fmt->precis)
	{
		fmt->precis = fmt->precis >= len ? len : fmt->precis;
		while (fmt->precis--)
		{
			*ret += ft_putwchar(*str++);
			fmt->width--;
		}
		while (fmt->width-- && fmt->width >= fmt->precis)
			*ret += ft_putchar(' ');
	}
	else if (fmt->width && !fmt->precis)
	{
		while (len--)
			*ret += ft_putwchar(*str++);
		while (fmt->width-- > ft_strlen(str) && fmt->width)
			*ret += ft_putchar(' ');
	}
}

void		ft_type_s(t_format *fmt, intmax_t varg, int *ret)
{
	char	*str;
	size_t	len;

	str = (wchar_t*)varg;
	len = ft_strlen(str);
	if (!ft_strchr(fmt->flags, '-'))
		ft_type_s_wp_pos(fmt, str, len, ret);
	else
		ft_type_s_wp_neg(fmt, str, len, ret);
}
