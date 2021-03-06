/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 19:33:56 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 19:08:04 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./printf.h"
#include <stdarg.h>
#include <locale.h>

int	main(void)
{
	int		ret;

	setlocale(LC_ALL, "");
	ft_putendl("FT_PRINTF");
	ret = ft_printf("[%.42S]\n", L"我是一只猫。");
	ft_printf("\nret: [%d]\n\n", ret - 3);
	ft_putendl("----*****----\n");
	ft_putendl("REAL PRINTF");
	ret = printf("[%.*S]\n", 42, L"我是一只猫。");
	printf("\nret: [%d]\n", ret - 3);
	return (0);
}
