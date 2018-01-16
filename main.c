/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 19:33:56 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/16 18:13:26 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>
#include <locale.h>

int	main(void)
{
	int	ret;

	setlocale(LC_ALL, "");
	ft_putendl("FT_PRINTF");
	ret = ft_printf("Char c = [%5lc], [%3.2s]\n", 127940, "hello");
	ft_printf("\nret: [%d]\n\n", ret);
	ft_putendl("----*****----\n");
	ft_putendl("REAL PRINTF");
	ret = printf("Char c = [%5lc], [%3.2s]\n", 127940, "hello");
	printf("\nret: [%d]\n", ret);
	return (0);
}
