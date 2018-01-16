/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_nb_len.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 14:23:33 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 15:48:31 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_len(int nb)
{
	int cnt;

	cnt = 1;
	if (nb < 0)
	{
		nb *= -1;
		cnt++;
	}
	while (nb >= 10)
	{
		cnt++;
		nb /= 10;
	}
	return (cnt);
}
