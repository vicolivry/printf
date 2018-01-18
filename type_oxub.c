/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_oxub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 18:17:06 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/18 13:41:21 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_type_oxub_pos(t_format *fmt, char *str, int len, int *ret)
{
	if (fmt->w && !fmt->p)
	{
		while (fmt->w-- > len && fmt->w)
			*ret += ft_putchar(' ');
	}
	else if (!fmt->w && fmt->p)
	{
		*ret += fmt->neg ? ft_putchar('-') : 0;
		while (fmt->p-- > len && fmt->p)
			*ret += ft_putchar('0');
	}
	else if (fmt->w && fmt->p)
	{
		while (fmt->w-- && fmt->w >= fmt->p)
			*ret += ft_putchar(' ');
		while (fmt->p-- && fmt->p >= len)
			*ret += ft_putchar('0');
	}
	*ret += fmt->t == 'p' ? ft_putstr("0x10") : 0;
	*ret += fmt->t == 'X' && ft_strchr(fmt->f, '#') ? ft_putstr("0X") : 0;
	*ret += fmt->t == 'x' && ft_strchr(fmt->f, '#') ? ft_putstr("0x") : 0;
	*ret += (fmt->t == 'o' || fmt->t == 'O') &&
		ft_strchr(fmt->f, '#') ? ft_putchar('0') : 0;
	*ret += ft_putstr(str);
}

static void	ft_type_oxub_neg(t_format *fmt, char *str, int len, int *ret)
{
	*ret += ft_strchr(fmt->f, '+') && !fmt->neg ? ft_putchar('+') : 0;
	if (fmt->p)
	{
		*ret += fmt->neg ? ft_putchar('-') : 0;
		while (fmt->p-- > len && fmt->p)
		{
			*ret += ft_putchar('0');
			fmt->w--;
		}
	}
	*ret += fmt->t == 'p' ? ft_putstr("0x10") : 0;
	*ret += fmt->t == 'X' && ft_strchr(fmt->f, '#') ? ft_putstr("0X") : 0;
	*ret += fmt->t == 'x' && ft_strchr(fmt->f, '#') ? ft_putstr("0x") : 0;
	*ret += (fmt->t == 'o' || fmt->t == 'O') &&
		ft_strchr(fmt->f, '#') ? ft_putchar('0') : 0;
	*ret += ft_putstr(str);
	if (fmt->w)
	{
		while (fmt->w-- > len && fmt->w)
			*ret += ft_putchar(' ');
	}
}

static void	ft_type_oxub_l(t_format *fmt, intmax_t *varg)
{
	if (fmt->l == 'H')
		*varg = (unsigned char)*varg;
	else if (fmt->l == 'h')
		*varg = (unsigned short)*varg;
	else if (fmt->l == ' ')
		*varg = (unsigned int)*varg;
	else if (fmt->l == 'l')
		*varg = (unsigned long)*varg;
	else if (fmt->l == 'L')
		*varg = (unsigned long long)*varg;
	else if (fmt->l == 'z')
		*varg = (size_t)*varg;
	else if (fmt->l == 'j')
		*varg = (intmax_t)*varg;
}

void		ft_type_oxub(t_format *fmt, intmax_t varg, int *ret)
{
	char	*str;
	int		len;

	fmt->l = fmt->t == 'O' ? 'l' : fmt->l;
	ft_type_oxub_l(fmt, &varg);
	str = ft_uitoa_base(varg, "01234567");
	str = fmt->t == 'u' ? ft_uitoa_base(varg, "0123456789") : str;
	str = fmt->t == 'x' || fmt->t == 'p'
		? ft_uitoa_base(varg, "0123456789abcdef") : str;
	str = fmt->t == 'X' ? ft_uitoa_base(varg, "0123456789ABCDEF") : str;
	str = fmt->t == 'b' ? ft_uitoa_base(varg, "01") : str;
	len = ft_strlen(str);
	len += fmt->t == 'p' ? 4 : 0;
	len += ft_strchr(fmt->f, '#') && (fmt->t == 'x' || fmt->t == 'X') ? 2 : 0;
	len += ft_strchr(fmt->f, '#') && (fmt->t == 'o' || fmt->t == 'O') ? 1 : 0;
	fmt->p = !fmt->p && !ft_strchr(fmt->f, '-') && (ft_strchr(fmt->f, '0'))
		? fmt->w : 0;
	if (!ft_strchr(fmt->f, '-'))
		ft_type_oxub_pos(fmt, str, len, ret);
	else
		ft_type_oxub_neg(fmt, str, len, ret);
}
