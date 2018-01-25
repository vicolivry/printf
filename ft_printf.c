/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 12:13:47 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 15:44:44 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
/*
   void		ft_display(t_format param)
   {
   ft_putchar('\n');
   ft_putchar('\n');
   ft_putstr("Plus : ");
   ft_putnbr(param.plus);
   ft_putchar('\n');
   ft_putstr("Minus : ");
   ft_putnbr(param.minus);
   ft_putchar('\n');
   ft_putstr("Space : ");
   ft_putnbr(param.space);
   ft_putchar('\n');
   ft_putstr("Hash : ");
   ft_putnbr(param.hash);
   ft_putchar('\n');
   ft_putstr("Zero : ");
   ft_putnbr(param.zero);
   ft_putchar('\n');
   ft_putstr("Width : ");
   ft_putnbr(param.w);
   ft_putchar('\n');
   ft_putstr("Precision : .");
   ft_putnbr(param.p);
   ft_putchar('\n');
   ft_putstr("Length : ");
   ft_putchar(param.l);
   ft_putchar('\n');
   ft_putstr("Type : ");
   ft_putchar(param.t);
   ft_putchar('\n');
   ft_putstr("Neg : ");
   ft_putnbr(param.neg);
   ft_putchar('\n');
   ft_putchar('\n');
   }*/

int	ft_printf(const char *format, ...)
{
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
			ft_modify(param, &va, &ret);
			str++;
		}
	}
	va_end(va);
	return (ret);
}
