/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_x.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 12:13:10 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 15:24:15 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	print_x(int *ret, t_format *fmt)
{
	*ret += fmt->t == 'X' && fmt->hash && !fmt->p_val ? ft_putstr("0X") : 0;
	*ret += fmt->t == 'x' && fmt->hash && !fmt->p_val ? ft_putstr("0x") : 0;
	fmt->t = ' ';
}

static void	ft_type_x_pos(t_format *fmt, char *str, int len, int *ret)
{
	if (fmt->w && !fmt->p)
	{
		while (!fmt->zero && fmt->w-- > len && fmt->w)
			*ret += ft_putchar(' ');
		print_x(ret, fmt);
		while (fmt->w-- > len && fmt->w && fmt->zero)
			*ret += ft_putchar('0');
	}
	else if (!fmt->w && fmt->p)
	{
		*ret += fmt->neg ? ft_putchar('-') : 0;
		print_x(ret, fmt);
		while (fmt->p-- > len && fmt->p)
			*ret += ft_putchar('0');
	}
	else if (fmt->w && fmt->p)
	{
		while (fmt->w-- && fmt->w >= len)
			*ret += fmt->zero ? ft_putchar('0') : ft_putchar(' ');
		while (fmt->p-- && fmt->p >= len)
			*ret += ft_putchar('0');
	}
	print_x(ret, fmt);
	*ret += ft_putstr(str);
}

static void	ft_type_x_neg(t_format *fmt, char *str, int len, int *ret)
{
	*ret += fmt->plus && !fmt->neg ? ft_putchar('+') : 0;
	if (fmt->p)
	{
		*ret += fmt->neg ? ft_putchar('-') : 0;
		while (fmt->p-- > len && fmt->p)
		{
			*ret += ft_putchar('0');
			fmt->w--;
		}
	}
	print_x(ret, fmt);
	*ret += ft_putstr(str);
	if (fmt->w)
		while (fmt->w-- > len && fmt->w)
			*ret += ft_putchar(' ');
}

static void	ft_type_x_l(t_format *fmt, intmax_t *varg)
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
		*varg = (uintmax_t)*varg;
}

void		ft_type_x(t_format *fmt, va_list *va, int *ret)
{
	char		*str;
	int			len;
	uintmax_t	varg;

	varg = u_size(va, fmt);
	str = fmt->t == 'x' ? ft_uitoa_base(varg, "0123456789abcdef")
		: ft_uitoa_base(varg, "0123456789ABCDEF");
	len = ft_strlen(str);
	len += fmt->hash ? 2 : 0;
	fmt->w += varg == 0 && fmt->p_val ? 1 : 0;
	if (varg == 0 && !fmt->p_val)
		*ret += ft_putchar('0');
	else if (!fmt->minus)
		ft_type_x_pos(fmt, str, len, ret);
	else
		ft_type_x_neg(fmt, str, len, ret);
}
