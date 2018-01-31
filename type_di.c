/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_di.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 16:21:34 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 15:55:47 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_type_d_pos(t_format *fmt, intmax_t varg, int *ret, int len)
{
	char	*str;

	str = ft_itoa_base(varg, 10);
	*ret += !fmt->plus && fmt->space && !fmt->neg && (fmt->w <= len
	|| (!ft_strcmp(str, "0"))) ? ft_putchar(' ') : 0;
	fmt->w -= !fmt->plus && fmt->space && !fmt->neg && !ft_strcmp(str, "0")
		? 1 : 0;
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
		ft_putstr(str);
	free(str);
}

static void	ft_type_d_neg(t_format *fmt, intmax_t varg, int *ret, int len)
{
	char*	str;

	str = ft_itoa_base(varg, 10);
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
	*ret += ft_putstr(str);
	if (fmt->w_val)
		while (fmt->w-- > len && fmt->w)
			*ret += ft_putchar(' ');
	free(str);
}

void		ft_type_di(t_format *fmt, va_list *va, int *ret)
{
	int			len;
	long long	varg;
	char		*tmp;

	fmt->l = fmt->t == 'D' ? 'l' : fmt->l;
	varg = d_size(va, fmt);
	tmp = ft_itoa_base(varg, 10);
	len = ft_strlen(tmp);
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
	fmt->p = varg && fmt->w_val && fmt->p_val && fmt->p < fmt->w
		&& fmt->p <= len ? len : fmt->p;
	fmt->w -= fmt->w_val && fmt->plus && !fmt->neg ? 1 : 0;
	if (!fmt->minus)
		ft_type_d_pos(fmt, varg, ret, len);
	else
		ft_type_d_neg(fmt, varg, ret, len);
	free(tmp);
}
