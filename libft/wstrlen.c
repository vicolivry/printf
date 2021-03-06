/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wstrlen.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 14:47:51 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 14:50:37 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	wstrlen(wchar_t *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += wchar_len(str[i]);
		i++;
	}
	return (len);
}
