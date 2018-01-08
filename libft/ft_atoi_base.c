/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 14:10:40 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 19:43:08 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_check_str(char *str, char *base)
{
	while (*str)
	{
		if (ft_strchr(base, *str) == NULL)
			return (0);
		str++;
	}
	return (1);
}

static int	ft_value(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

static int	ft_check_base(char *str)
{
	int	i;
	int	j;

	i= 0;
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

int			ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	b;
	int	pwr;

	nb = 0;
	b = ft_strlen(base);
	if (!ft_check_str(str, base) || !ft_check_base(base))
		return (0);
	pwr = ft_strlen(str) - 1;
	while (*str)
	{
		nb += ft_value(base, *str) * ft_power(b, pwr);
		pwr--;
		str++;
	}
	return (nb);
}
