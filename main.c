/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 19:33:56 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 18:45:57 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./printf.h"
#include <stdarg.h>
#include <locale.h>

int	main(void)
{

	int		ret;
	char	*str = "abcd";
	int		*bec;

	setlocale(LC_ALL, "");
	ft_putendl("FT_PRINTF");
	ret = ft_printf("%c", '\0');
	ft_printf("\nret: [%d]\n\n", ret - 3);
	ft_putendl("----*****----\n");
	ft_putendl("REAL PRINTF");
	ret = printf("%D", LONG_MAX);
	printf("\nret: [%d]\n", ret - 3);
	return (0);
}
