/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 19:33:56 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 20:19:46 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>

int	main(void)
{
	int	ret;

	ft_putendl("FT_PRINTF");
	ret = ft_printf("Number - 14.6d %- 14.6d, %-+4.5d\n", 101, -42);
	ret = ft_printf("Number - 10.6d %- 10.6d, %-+4.5d\n", 101, -42);
	ret = ft_printf("Number - 9.6d %- 9.6d, %-+4.5d\n", 101, -42);
	ret = ft_printf("Number - 8.6d %- 8.6d, %-+4.5d\n", 101, -42);
	ret = ft_printf("Number - 7.6d %- 7.6d, %-+4.5d\n", 101, -42);
	ret = ft_printf("Number - 6.6d %- 6.6d, %-+4.5d\n", 101, -42);
	ret = ft_printf("Number - 5.6d %- 5.6d, %-+4.5d\n", 101, -42);
	ret = ft_printf("Number - 4.6d %- 4.6d, %-+4.5d\n", 101, -42);
	ft_printf("\nret: [%d]\n\n", ret);
	ft_putendl("----*****----\n");
	ft_putendl("REAL PRINTF");
	ret = printf("Number - 14.6d %- 14.6d, %-+4.5d\n", 101, -42);
	ret = printf("Number - 10.6d %- 10.6d, %-+4.5d\n", 101, -42);
	ret = printf("Number - 9.6d %- 9.6d, %-+4.5d\n", 101, -42);
	ret = printf("Number - 8.6d %- 8.6d, %-+4.5d\n", 101, -42);
	ret = printf("Number - 7.6d %- 7.6d, %-+4.5d\n", 101, -42);
	ret = printf("Number - 6.6d %- 6.6d, %-+4.5d\n", 101, -42);
	ret = printf("Number - 5.6d %- 5.6d, %-+4.5d\n", 101, -42);
	ret = printf("Number - 4.6d %- 4.6d, %-+4.5d\n", 101, -42);
	printf("\nret: [%d]\n", ret);
	return (0);
}
