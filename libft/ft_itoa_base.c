/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/05 17:57:32 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 19:21:25 by volivry     ###    #+. /#+    ###.fr     */
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

static int	ft_nb_len(int nb, int base)
{
	int	cnt;

	cnt = 1;
	if (nb < 0)
	{
		nb *= -1;
		cnt++;
	}
	while (nb >= base)
	{
		cnt++;
		nb /= base;
	}
	return (cnt);
}

char		*ft_itoa_base(int nb, char *base_str)
{
	int		b;
	char	*str;
	int		len;

	if (!ft_check_base(base_str))
		return (NULL);
	b = ft_strlen(base_str);
	len = ft_nb_len(nb, b);
	if ((str = malloc(len + 1)) == NULL)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	str[len] = '\0';
	len--;
	while (nb > 0)
	{
		str[len] = (base_str[nb % b]);
		nb /= b;
		len--;
	}
	return (str);
}
