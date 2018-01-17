/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 17:24:14 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 18:34:42 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_init_format(t_format *struc)
{
	ft_bzero(struc->f, 6);
	struc->w = 0;
	struc->p = 0;
	struc->l = ' ';
	struc->t = ' ';
	struc->neg = 0;
}

static void	ft_fill_fmt(char **str, t_format *fmt, int *flag_cnt)
{
	if (ft_strchr(FLAGS, **str) != NULL)
	{
		ft_format_flags(str, fmt, *flag_cnt);
		*flag_cnt = *flag_cnt + 1;
	}
	else if (ft_strchr(WIDTH, **str) != NULL)
		ft_format_width(str, fmt);
	else if (**str == '.')
		ft_format_precis(str, fmt);
	else if (ft_strchr(LENGTH, **str) != NULL)
		ft_format_length(str, fmt);
}

t_format	ft_parse(char **str)
{
	t_format	fmt;
	int			flag_cnt;

	flag_cnt = 0;
	ft_init_format(&fmt);
	*str = *str + 1;
	while (ft_strchr(TYPE, **str) == NULL)
		ft_fill_fmt(str, &fmt, &flag_cnt);
	fmt.t = **str;
	if (fmt.t == 'p')
	{
		fmt.t = 'x';
	if (!ft_strchr(fmt.f, '#'))
		fmt.f[flag_cnt] = '#';
	}
	return (fmt);
}
