/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 19:33:56 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 16:03:14 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./printf.h"
#include <stdarg.h>
#include <locale.h>

int	main(void)
{
	int		ret;
	uintmax_t	i = -2147483648;
	char	*str = "abc";

	setlocale(LC_ALL, "");
	ft_putendl("FT_PRINTF");
	ret = ft_printf("[@moulitest: %s, %10d]\n", str, 23);
	ft_printf("\nret: [%d]\n\n", ret - 3);
	ft_putendl("----*****----\n");
	ft_putendl("REAL PRINTF");
	ret = printf("[@moulitest: %s, %10d]\n", str, 23);
	printf("\nret: [%d]\n", ret - 3);
	return (0);
}
