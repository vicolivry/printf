/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modify.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 17:57:07 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 17:32:51 by volivry     ###    #+. /#+    ###.fr     */
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
	else if (fmt.t == 's' || fmt.t == 'S')
		ft_type_s(&fmt, varg, ret);
	else if (fmt.t == 'o' || fmt.t == 'O' || fmt.t == 'x'
			|| fmt.t == 'X' || fmt.t == 'u' || fmt.t == 'b')
		ft_type_oxub(&fmt, varg, ret);
}
