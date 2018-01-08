/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 19:33:56 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 17:36:15 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int main(int argc, char **argv)
{
	t_format	fmt;

	if (argc != 2)
		return (0);

	fmt = ft_parse(argv[1]);
	ft_putstr("Flags : ");
	ft_putendl(fmt.flags);
	ft_putstr("Width : ");
	ft_putnbr(fmt.width);
	ft_putchar('\n');
	ft_putstr("Precision : .");
	ft_putnbr(fmt.precis);
	ft_putchar('\n');
	ft_putstr("Length : ");
	ft_putchar(fmt.length);
	ft_putchar('\n');
	ft_putstr("Type :");
	ft_putchar(fmt.type);
	ft_putchar('\n');
	return 0;
}
