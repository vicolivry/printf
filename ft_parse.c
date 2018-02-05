/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 17:24:14 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 19:07:04 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void		ft_init_format(t_format *struc)
{
	struc->plus = 0;
	struc->minus = 0;
	struc->hash = 0;
	struc->space = 0;
	struc->zero = 0;
	struc->w = 0;
	struc->p = 0;
	struc->p_val = 0;
	struc->w_val = 0;
	struc->l = ' ';
	struc->t = ' ';
	struc->neg = 0;
	struc->mod = ' ';
}

static void	ft_fill_fmt(const char **str, t_format *fmt, int *flag_cnt)
{
	if (ft_strchr(FLAGS, **str) != NULL)
		ft_format_flags(str, fmt);
	else if (ft_strchr(WIDTH, **str) != NULL)
		ft_format_width(str, fmt);
	else if (**str == '.')
		ft_format_precis(str, fmt);
	else if (ft_strchr(LENGTH, **str) != NULL)
		ft_format_length(str, fmt);
}

t_format	ft_parse(const char **str)
{
	t_format	fmt;
	int			flag_cnt;

	flag_cnt = 0;
	ft_init_format(&fmt);
	*str = *str + 1;
	while (ft_strchr(FORMAT, **str))
		ft_fill_fmt(str, &fmt, &flag_cnt);
	if (ft_strchr(TYPE, **str))
		fmt.t = **str;
	else
	{
		fmt.t = 'c';
		fmt.mod = **str;
	}
	return (fmt);
}
