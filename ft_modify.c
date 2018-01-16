/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modify.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 17:57:07 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 12:06:27 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	ft_modify(t_format fmt, intmax_t varg, int *ret)
{
	if (fmt.type == 'd' || fmt.type == 'i' || fmt.type == 'D')
		ft_type_di(&fmt, varg, ret);
	else if (fmt.type == 'c' || fmt.type == 'C' || fmt.type == '%')
		ft_type_c(&fmt, varg, ret);
	else if (fmt.type == 's' || fmt.type == 'S')
		ft_type_s(&fmt, varg, ret);
}
