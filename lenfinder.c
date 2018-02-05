/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lenfinder.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:49:01 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 18:49:53 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int	lenfinder(t_format *fmt, wchar_t *str)
{
	int	len;
	int	p;

	len = 0;
	p = fmt->p;
	if (fmt->p_val && fmt->p < wchar_len(str[0]))
		fmt->w++;
	if (fmt->p_val && p < wstrlen(str))
		while (p >= wchar_len(*str))
		{
			p -= wchar_len(*str);
			len += wchar_len(*str++);
		}
	else
		len = wstrlen(str);
	return (len);
}
