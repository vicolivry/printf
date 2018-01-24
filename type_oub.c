/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   type_oub.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 12:23:12 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:52:48 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_type_oub_pos(t_format *fmt, char *str, int len, int *ret)
{
	if (fmt->w && !fmt->p)
		while (fmt->w-- > len && fmt->w)
			*ret += fmt->zero ? ft_putchar('0') : ft_putchar(' ');
	else if (!fmt->w && fmt->p)
	{
		*ret += fmt->neg ? ft_putchar('-') : 0;
		while (fmt->p-- > len && fmt->p)
			*ret += ft_putchar('0');
	}
	else if (fmt->w && fmt->p)
	{
		while (fmt->w-- && fmt->w >= len)
			*ret += ft_putchar(' ');
		while (fmt->p-- && fmt->p >= len)
			*ret += ft_putchar('0');
	}
	*ret += (fmt->t == 'o' || fmt->t == 'O') &&
		fmt->hash ? ft_putchar('0') : 0;
	*ret += ft_putstr(str);
}

static void	ft_type_oub_neg(t_format *fmt, char *str, int len, int *ret)
{
	*ret += fmt->plus && !fmt->neg ? ft_putchar('+') : 0;
	if (fmt->p_val)
	{
		*ret += fmt->neg ? ft_putchar('-') : 0;
		while (fmt->p-- > len && fmt->p)
		{
			*ret += ft_putchar('0');
			fmt->w--;
		}
	}
	*ret += (fmt->t == 'o' || fmt->t == 'O') &&
		fmt->hash ? ft_putchar('0') : 0;
	*ret += ft_putstr(str);
	if (fmt->w_val)
		while (fmt->w-- > len && fmt->w)
			*ret += ft_putchar(' ');
}

static void	ft_type_oub_l(t_format *fmt, intmax_t *varg)
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

void		ft_type_oub(t_format *fmt, intmax_t varg, int *ret)
{
	char	*str;
	int		len;

	fmt->l = fmt->t == 'O' ? 'l' : fmt->l;
	ft_type_oub_l(fmt, &varg);
	str = ft_uitoa_base(varg, "01234567");
	str = fmt->t == 'u' ? ft_uitoa_base(varg, "0123456789") : str;
	str = fmt->t == 'b' ? ft_uitoa_base(varg, "01") : str;
	len = ft_strlen(str);
	len += fmt->hash && (fmt->t == 'o' || fmt->t == 'O') ? 1 : 0;
	fmt->w += varg == 0 && fmt->p_val ? 1 : 0;
	if (varg == 0 && !fmt->p_val)
		*ret += ft_putchar('0');
	else if (!fmt->minus)
		ft_type_oub_pos(fmt, str, len, ret);
	else
		ft_type_oub_neg(fmt, str, len, ret);
}
