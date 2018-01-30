/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_di.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 16:21:34 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 19:22:04 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_type_d_pos(t_format *fmt, intmax_t varg, int *ret, int len)
{
	*ret += !fmt->plus && fmt->space && !fmt->neg && fmt->w <= len
		? ft_putchar(' ') : 0;
	if (fmt->w_val && !fmt->p_val)
	{
		while (!fmt->zero && fmt->w-- > len && fmt->w)
			*ret += ft_putchar(' ');
		*ret += fmt->plus && !fmt->neg ? ft_putchar('+') : 0;
		*ret += fmt->neg ? ft_putchar('-') : 0;
		while (fmt->zero && fmt->w-- > len && fmt->w)
			*ret += ft_putchar('0');
	}
	else if (!fmt->w_val && fmt->p_val)
	{
		*ret += fmt->plus && !fmt->neg ? ft_putchar('+') : 0;
		*ret += fmt->neg ? ft_putchar('-') : 0;
		while (fmt->p-- > len && fmt->p)
			*ret += ft_putchar('0');
	}
	else if (fmt->w_val && fmt->p_val)
	{
		while (!fmt->zero && fmt->p_val && fmt->w-- && fmt->w >= fmt->p)
			*ret += ft_putchar(' ');
		*ret += fmt->plus && !fmt->neg ? ft_putchar('+') : 0;
		*ret += fmt->neg ? ft_putchar('-') : 0;
		while (fmt->zero && !fmt->p_val && fmt->w-- && fmt->w >= fmt->p)
			*ret += ft_putchar('0');
		while (fmt->p-- && fmt->p >= len)
			*ret += ft_putchar('0');
	}
	else
	{
		*ret += fmt->plus && !fmt->neg ? ft_putchar('+') : 0;
		*ret += fmt->neg ? ft_putchar('-') : 0;
	}
	*ret += fmt->p < 0 && fmt->p_val && !varg ? 0 :
		ft_putstr(ft_itoa_base(varg, 10));
}

static void	ft_type_d_neg(t_format *fmt, intmax_t varg, int *ret, int len)
{
	*ret += !fmt->plus && fmt->space && !fmt->neg ? ft_putchar(' ') : 0;
	fmt->w -= !fmt->plus && fmt->space && !fmt->neg ? 1 : 0;
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
	*ret += fmt->neg ? ft_putchar('-') : 0;
	*ret += ft_putstr(ft_itoa_base(varg, 10));
	if (fmt->w_val)
		while (fmt->w-- > len && fmt->w)
			*ret += ft_putchar(' ');
}

void		ft_type_di(t_format *fmt, va_list *va, int *ret)
{
	int			len;
	long long	varg;

	varg = d_size(va, fmt);
	fmt->l = fmt->t == 'D' ? 'l' : fmt->l;
	len = ft_strlen(ft_itoa_base(varg, 10));
	if (varg == -9223372036854775808)
	{
		*ret += ft_putstr("-9223372036854775808");
		return ;
	}
	if (varg < 0)
	{
		varg *= -1;
		fmt->neg = 1;
		fmt->p += fmt->p_val ? 1 : 0;
	}
	if (fmt->zero && fmt->p_val && fmt->w_val)
		fmt->zero = 0;
	fmt->w -= fmt->w_val && fmt->plus && !fmt->neg ? 1 : 0;
	if (!fmt->minus)
		ft_type_d_pos(fmt, varg, ret, len);
	else
		ft_type_d_neg(fmt, varg, ret, len);
}
