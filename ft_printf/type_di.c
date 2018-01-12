/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_di.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 16:21:34 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 20:16:42 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_type_d_pos(t_format *fmt, intmax_t varg, int *ret)
{
	fmt->width -= ft_strchr(fmt->flags, '+') && !fmt->neg ? 1 : 0;
	*ret += !ft_strchr(fmt->flags, '+') && ft_strchr(fmt->flags, ' ')
		&& !fmt->neg && fmt->width <= ft_nb_len(varg) ? ft_putchar(' ') : 0;
	if (fmt->width && !fmt->precis)
	{
		while (fmt->width-- > ft_nb_len(varg) && fmt->width)
			*ret += ft_putchar(' ');
		*ret += ft_strchr(fmt->flags, '+') && !fmt->neg ? ft_putchar('+') : 0;
	}
	else if (!fmt->width && fmt->precis)
	{
		*ret += ft_strchr(fmt->flags, '+') && !fmt->neg ? ft_putchar('+') : 0;
		*ret += fmt->neg ? ft_putchar('-') : 0;
		while (fmt->precis-- > ft_nb_len(varg) && fmt->precis)
			*ret += ft_putchar('0');
	}
	else if (fmt->width && fmt->precis)
	{
		while (fmt->width-- && fmt->width >= fmt->precis)
			*ret += ft_putchar(' ');
		*ret += ft_strchr(fmt->flags, '+') && !fmt->neg ? ft_putchar('+') : 0;
		while (fmt->precis-- && fmt->precis > ft_nb_len(varg))
			*ret += ft_putchar('0');
	}
	*ret += ft_putstr(ft_itoa(varg));
}

static void	ft_type_d_neg(t_format *fmt, intmax_t varg, int *ret)
{
	int	tmp;

	tmp = fmt->precis;
	fmt->width -= ft_strchr(fmt->flags, '+') && !fmt->neg ? 1 : 0;
	*ret += !ft_strchr(fmt->flags, '+') && ft_strchr(fmt->flags, ' ')
		&& !fmt->neg && fmt->width-- <= ft_nb_len(varg) ? ft_putchar(' ') : 0;
	*ret += ft_strchr(fmt->flags, '+') && !fmt->neg ? ft_putchar('+') : 0;
	if (fmt->precis)
	{
		*ret += fmt->neg ? ft_putchar('-') : 0;
		while (fmt->precis-- > ft_nb_len(varg) && fmt->precis)
		{
			*ret += ft_putchar('0');
			fmt->width--;
		}
	}
	*ret += ft_putstr(ft_itoa(varg));
	if (fmt->width)
	{
		while (fmt->width-- > ft_nb_len(varg)  && fmt->width)
			*ret += ft_putchar(' ');
	}
}

static void	ft_type_d_l(t_format *fmt, intmax_t *varg)
{
	if (fmt->length == 'H')
		*varg = (signed char)*varg;
	else if (fmt->length == 'h')
		*varg = (short)*varg;
	else if (fmt->length == ' ')
		*varg = (int)*varg;
	else if (fmt->length == 'l')
		*varg = (long)*varg;
	else if (fmt->length == 'L')
		*varg = (long long)*varg;
	else if (fmt->length == 'z')
		*varg = (size_t)*varg;
	else if (fmt->length == 'j')
		*varg = (intmax_t)*varg;
}

void		ft_type_di(t_format *fmt, intmax_t varg, int *ret)
{
	ft_type_d_l(fmt, &varg);
	if (!ft_strchr(fmt->flags, '-'))
		ft_type_d_pos(fmt, varg, ret);
	else
		ft_type_d_neg(fmt, varg, ret);
}
