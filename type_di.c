/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_di.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 16:21:34 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 17:13:38 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_type_d_pos(t_format *fmt, intmax_t varg, int *ret)
{
	*ret += !ft_strchr(fmt->f, '+') && ft_strchr(fmt->f, ' ')
		&& !fmt->neg && fmt->w <= ft_nb_len(varg) ? ft_putchar(' ') : 0;
	if (fmt->w && !fmt->p)
	{
		while (fmt->w-- > ft_nb_len(varg) && fmt->w)
			*ret += ft_putchar(' ');
		*ret += ft_strchr(fmt->f, '+') && !fmt->neg ? ft_putchar('+') : 0;
	}
	else if (!fmt->w && fmt->p)
	{
		*ret += ft_strchr(fmt->f, '+') && !fmt->neg ? ft_putchar('+') : 0;
		*ret += fmt->neg ? ft_putchar('-') : 0;
		while (fmt->p-- > ft_nb_len(varg) && fmt->p)
			*ret += ft_putchar('0');
	}
	else if (fmt->w && fmt->p)
	{
		while (fmt->w-- && fmt->w >= fmt->p)
			*ret += ft_putchar(' ');
		*ret += ft_strchr(fmt->f, '+') && !fmt->neg ? ft_putchar('+') : 0;
		while (fmt->p-- && fmt->p > ft_nb_len(varg))
			*ret += ft_putchar('0');
	}
	*ret += fmt->neg ? ft_putchar('-') : 0;
	*ret += ft_putstr(ft_itoa(varg));
}

static void	ft_type_d_neg(t_format *fmt, intmax_t varg, int *ret)
{
	*ret += !ft_strchr(fmt->f, '+') && ft_strchr(fmt->f, ' ')
		&& !fmt->neg ? ft_putchar(' ') : 0;
	fmt->w -= !ft_strchr(fmt->f, '+') && ft_strchr(fmt->f, ' ')
		&& !fmt->neg ? 1 : 0;
	*ret += ft_strchr(fmt->f, '+') && !fmt->neg ? ft_putchar('+') : 0;
	if (fmt->p)
	{
		*ret += fmt->neg ? ft_putchar('-') : 0;
		while (fmt->p-- > ft_nb_len(varg) && fmt->p)
		{
			*ret += ft_putchar('0');
			fmt->w--;
		}
	}
	*ret += ft_putstr(ft_itoa(varg));
	if (fmt->w)
	{
		while (fmt->w-- > ft_nb_len(varg) && fmt->w)
			*ret += ft_putchar(' ');
	}
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

void		ft_type_di(t_format *fmt, intmax_t varg, int *ret)
{
	fmt->l = fmt->t == 'D' ? 'l' : fmt->l;
	varg = (int)varg;
	ft_type_d_l(fmt, &varg);
	if (varg < 0)
	{
		varg *= -1;
		fmt->neg = 1;
	}
	fmt->w -= ft_strchr(fmt->f, '+') && !fmt->neg ? 1 : 0;
	if (!ft_strchr(fmt->f, '-'))
		ft_type_d_pos(fmt, varg, ret);
	else
		ft_type_d_neg(fmt, varg, ret);
}
