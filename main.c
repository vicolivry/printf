/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 19:33:56 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 18:40:57 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <locale.h>

int	main(void)
{
	int	ret;
	char	*str = "abc";

	setlocale(LC_ALL, "");
	ft_putendl("FT_PRINTF");
	ret = ft_printf("Char c = [ %lc  ], [%b]\n", 128025, 160);
	ft_printf("\nret: [%d]\n\n", ret);
	ft_putendl("----*****----\n");
	ft_putendl("REAL PRINTF");
	ret = printf("Char c = [ %lc  ], [%p]\n", 128025, str);
	printf("\nret: [%d]\n", ret);
	return (0);
}
