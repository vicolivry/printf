/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_uitoa_base.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 19:18:47 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 19:47:12 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(str) < 2)
		return (0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_ui_len(unsigned int nb)
{
	int	cnt;

	cnt = 1;
	while (nb >= 10)
	{
		cnt++;
		nb /= 10;
	}
	return (cnt);
}

char		*ft_uitoa_base(unsigned int nb, char *base)
{
	int		b;
	char	*str;
	int		len;

	if (!ft_check_base(base))
		return (NULL);
	len = ft_ui_len(nb);
	if ((str = malloc(len + 1)) == NULL)
		return (NULL);
	b = ft_strlen(base);
	while (nb > 0)
	{
		str[len] = (base[nb % b]);
		nb /= b;
		len--;
	}
	return (str);
}
