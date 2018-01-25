/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modify.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 17:57:07 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 15:01:56 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	ft_modify(t_format fmt, va_list *va, int *ret)
{
	if (fmt.t == 'd' || fmt.t == 'i' || fmt.t == 'D')
		ft_type_di(&fmt, va, ret);
	else if (fmt.t == 'c' || fmt.t == 'C' || fmt.t == '%')
		ft_type_c(&fmt, va, ret);
	else if (fmt.t == 's')
		ft_type_s(&fmt, va, ret);
	else if (fmt.t == 'o' || fmt.t == 'O' || fmt.t == 'u' || fmt.t == 'b')
		ft_type_oub(&fmt, va, ret);
	else if (fmt.t == 'x' || fmt.t == 'X')
		ft_type_x(&fmt, va, ret);
}
