/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modify.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/09 17:57:07 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 17:21:06 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

void	ft_modify(t_format fmt, intmax_t varg, int *ret)
{
	if (fmt.type == 'd' || fmt.type == 'i' || fmt.type == 'D')
	{
		fmt.length = fmt.type == 'D' ? 'l' : fmt.length;
		varg = (int)varg;
		if (varg < 0)
		{
			varg *= -1;
			fmt.neg = 1;
		}
		ft_type_di(&fmt, varg, ret);
	}
}
