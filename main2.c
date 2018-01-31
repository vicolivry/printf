/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main2.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 10:24:48 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 10:26:45 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./printf.h"

int main()
{
	int		i = 42;
	char	*ii = "42";

	ft_putstr("my printf\n");
	ft_printf("\n%#o", 42);
	ft_printf("\n%#x", 42);
	ft_printf("\n%u", 42);
	ft_printf("\n%d", 42);
	ft_printf("\n%p", &i);
	ft_printf("\n%p", &ii);
	ft_printf("\n%5c", 42);
	ft_printf("\n%.6s", "42");
	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);
	ft_putstr("\nprintf\n");
	printf("\n%#o", 42);
	printf("\n%#x", 42);
	printf("\n%u", 42);
	printf("\n%d", 42);
	printf("\n%p", &i);
	printf("\n%p", &ii);
	printf("\n%5c", 42);
	printf("\n%.6s", "42");
	printf("\n");
	printf("%%\n");
	printf("%d\n", 42);
	printf("%d%d\n", 42, 41);
	printf("%d%d%d\n", 42, 43, 44);
	printf("%ld\n", 2147483647);
	printf("%lld\n", 9223372036854775807);
	printf("%x\n", 505);
	printf("%X\n", 505);
	printf("%p\n", &ft_printf);
	printf("%20.15d\n", 54321);
	printf("%-10d\n", 3);
	printf("% d\n", 3);
	printf("%+d\n", 3);
	printf("%010d\n", 1);
	printf("%hhd\n", 0);
	printf("%jd\n", 9223372036854775807);
	printf("%zd\n", 4294967295);
	printf("%\n");
	printf("%U\n", 4294967295);
	printf("%u\n", 4294967295);
	printf("%o\n", 40);
	printf("%%#08x\n", 42);
	printf("%x\n", 1000);
	printf("%#X\n", 1000);
	printf("%s\n", NULL);
	printf("%S\n", L"ݗݜशব");
	printf("%s%s\n", "test", "test");
	printf("%s%s%s\n", "test", "test", "test");
	printf("%C\n", 15000);
}
