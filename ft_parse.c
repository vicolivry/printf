/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 17:24:14 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 15:49:16 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static void	ft_init_format(t_format *struc)
{
	ft_bzero(struc->flags, 6);
	struc->width = 0;
	struc->precis = 0;
	struc->length = 0;
	struc->type = ' ';
}

static void	ft_fill_fmt(char **str, t_format *format, int *flag_cnt)
{
	if (ft_strchr(FLAGS, **str) != NULL)
	{
		ft_format_flags(str, format, *flag_cnt);
		*flag_cnt = *flag_cnt + 1;
	}
	else if (ft_strchr(WIDTH, **str) != NULL)
		ft_format_width(str, format);
	else if (**str == '.')
		ft_format_precis(str, format);
	else if (ft_strchr(LENGTH, **str) != NULL)
		ft_format_length(str, format);
}

t_format	ft_parse(char *str)
{
	t_format	format;
	int			flag_cnt;

	flag_cnt = 0;
	ft_init_format(&format);
	while (str)
	{
		if (*str == '%')
		{
			ft_init_format(&format);
			str++;
			while (ft_strchr(TYPE, *str) == NULL)
				ft_fill_fmt(&str, &format, &flag_cnt);
			format.type = *str;
			str++;
			return (format);
		}
		str++;
	}
	return (format);
}

