/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 12:10:35 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 20:05:35 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char const *s, int fd)
{
	int		ret;
	size_t	i;
	char	*str;

	i = 0;
	ret = 0;
	str = (char*)s;
	if (s != NULL)
	{
		while (str[i])
		{
			ret += ft_putchar_fd(str[i], fd);
			i++;
		}
	}
	return (ret);
}
