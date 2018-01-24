/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modify.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 17:57:07 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 19:04:25 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	ft_modify(t_format fmt, intmax_t varg, int *ret)
{
	if (fmt.t == 'd' || fmt.t == 'i' || fmt.t == 'D')
		ft_type_di(&fmt, varg, ret);
	else if (fmt.t == 'c' || fmt.t == 'C' || fmt.t == '%')
		ft_type_c(&fmt, varg, ret);
	else if (fmt.t == 's')
		ft_type_s(&fmt, varg, ret);
	else if (fmt.t == 'o' || fmt.t == 'O' || fmt.t == 'u' || fmt.t == 'b')
		ft_type_oub(&fmt, varg, ret);
	 else if (fmt.t == 'x' || fmt.t == 'X')
		ft_type_x(&fmt, varg, ret);
}
