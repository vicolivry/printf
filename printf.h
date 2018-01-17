/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 13:42:25 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 17:33:08 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <inttypes.h>

# define FORMAT "-+ 0#123456789.hlLzjt"
# define FLAGS "-+ 0#"
# define WIDTH "123456789"
# define PRECIS '.'
# define LENGTH "hlzj"
# define TYPE "bsSpdDioOuUxXcC%"

typedef struct		s_format
{
	char			f[6];
	int				w;
	int				p;
	char			l;
	char			t;
	int				neg;
}					t_format;

t_format			ft_parse(char **str);
void				ft_format_flags(char **str, t_format *format, int i);
void				ft_format_width(char **str, t_format *format);
void				ft_format_precis(char **str, t_format *format);
void				ft_format_length(char **str, t_format *format);
void				ft_format_type(char **str, t_format *format);
int					ft_printf(const char *format, ...);
void				ft_modify(t_format fmt, intmax_t varg, int *ret);
void				ft_type_di(t_format *fmt, intmax_t varg, int *ret);
void				ft_type_c(t_format *fmt, intmax_t varg, int *ret);
void				ft_type_s(t_format *fmt, intmax_t varg, int *ret);
void				ft_type_oxub(t_format *fmt, intmax_t varg, int *ret);

#endif
