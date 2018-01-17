/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 12:13:47 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 17:26:42 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
/*
static void	ft_display_param(t_format param)
{
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr("Flags : ");
	ft_putendl(param.flags);
	ft_putstr("Width : ");
	ft_putnbr(param.width);
	ft_putchar('\n');
	ft_putstr("Precision : .");
	ft_putnbr(param.precis);
	ft_putchar('\n');
	ft_putstr("Length : ");
	ft_putchar(param.length);
	ft_putchar('\n');
	ft_putstr("Type : ");
	ft_putchar(param.type);
	ft_putchar('\n');
	ft_putstr("Neg : ");
	ft_putnbr(param.neg);
	ft_putchar('\n');
	ft_putchar('\n');
}*/

int	ft_printf(const char *format, ...)
{
	intmax_t	varg;
	va_list		va;
	t_format	param;
	char		*str;
	int			ret;

	ret = 0;
	va_start(va, format);
	if (!(str = ft_strdup((char*)format)))
		return (0);
	while (*str)
	{
		while (*str != '%' && *str)
			ret += ft_putchar(*str++);
		if (*str == '%')
		{
			param = ft_parse(&str);
			if (param.t != '%')
				varg = va_arg(va, intmax_t);
		//	ft_display_param(param);
			ft_modify(param, varg, &ret);
			str++;
		}
	}
	va_end(va);
	return (ret);
}
