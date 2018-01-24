/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_di.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 16:21:34 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:36:31 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_type_d_pos(t_format	 *fmt, long varg, int *ret, int len)
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
	*ret += varg ? ft_putstr(ft_itoa(varg)) : 0;
	*ret += !varg && fmt->plus ? ft_putchar('0') : 0;
}

static void	ft_type_d_neg(t_format *fmt, long varg, int *ret, int len)
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
	*ret += ft_putstr(ft_itoa(varg));
	if (fmt->w_val)
		while (fmt->w-- > len && fmt->w)
			*ret += ft_putchar(' ');
}

static void	ft_type_d_l(t_format *fmt, intmax_t *varg)
{
	if (fmt->l == 'H')
		*varg = (signed char)*varg;
	else if (fmt->l == 'h')
		*varg = (short)*varg;
	else if (fmt->l == ' ')
		*varg = (int)*varg;
	else if (fmt->l == 'l')
		*varg = (long)*varg;
	else if (fmt->l == 'L')
		*varg = (long long)*varg;
	else if (fmt->l == 'z')
		*varg = (size_t)*varg;
	else if (fmt->l == 'j')
		*varg = (intmax_t)*varg;
}

void	ft_type_di(t_format *fmt, intmax_t varg, int *ret)
{
	int	len;
	int	i;

	i = 0;
	varg = (int)varg;
	len = ft_strlen(ft_itoa(varg));
	fmt->l = fmt->t == 'D' ? 'l' : fmt->l;
	ft_type_d_l(fmt, &varg);
	if (varg < 0)
	{
		varg *= -1;
		fmt->neg = 1;
	}
	if (fmt->zero && fmt->p_val && fmt->w_val)
		fmt->zero = 0;
	fmt->w -= fmt->w_val && fmt->plus && !fmt->neg ? 1 : 0;
	if (!fmt->minus)
		ft_type_d_pos(fmt, varg, ret, len);
	else
		ft_type_d_neg(fmt, varg, ret, len);
}
