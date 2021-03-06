/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: volivry <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/03 13:42:25 by volivry      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 19:07:19 by volivry     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <inttypes.h>
# include <limits.h>
# include <stdlib.h>

# define FORMAT "-+ 0#123456789.hlLzjt"
# define FLAGS "-+ 0#"
# define WIDTH "123456789"
# define PRECIS '.'
# define LENGTH "hlzj"
# define TYPE "bsSpdDioOuUxXcC%"

typedef struct		s_format
{
	int				plus;
	int				minus;
	int				hash;
	int				space;
	int				zero;
	int				w;
	int				p;
	int				w_val;
	int				p_val;
	char			l;
	char			t;
	int				neg;
	char			mod;
}					t_format;

t_format			ft_parse(const char **str);
intmax_t			d_size(va_list *ap, t_format *fmt);
uintmax_t			u_size(va_list *ap, t_format *fmt);
void				ft_format_flags(const char **str, t_format *format);
void				ft_format_width(const char **str, t_format *format);
void				ft_format_precis(const char **str, t_format *format);
void				ft_format_length(const char **str, t_format *format);
void				ft_format_type(const char **str, t_format *format);
int					ft_printf(const char *format, ...);
void				ft_modify(t_format fmt, va_list *va, int *ret);
void				ft_type_di(t_format *fmt, va_list *va, int *ret);
void				ft_type_c(t_format *fmt, va_list *va, int *ret);
void				ft_type_s(t_format *fmt, va_list *va, int *ret);
void				ft_type_oub(t_format *fmt, va_list *va, int *ret);
void				ft_type_x(t_format *fmt, va_list *va, int *ret);
void				ft_type_p(t_format *fmt, va_list *va, int *ret);
void				ft_type_ws(t_format *fmt, va_list *va, int *ret);
void				ft_init_format(t_format *struc);
int					lenfinder(t_format *fmt, wchar_t *str);

#endif
