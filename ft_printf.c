/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 12:13:47 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 14:53:37 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		va;
	t_format	param;
	char		*str;
	int			ret;

	ret = 0;
	va_start(va, format);
	while (*format)
	{
		while (*format != '%' && *format)
			ret += ft_putchar(*format++);
		if (*format == '%')
		{
			if (!ft_strcmp(format, "%"))
				return (0);
			param = ft_parse(&format);
			ft_modify(param, &va, &ret);
			format++;
		}
	}
	va_end(va);
	return (ret);
}
