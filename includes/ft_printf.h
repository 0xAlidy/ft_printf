/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alidy <alidy@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 00:53:34 by alidy        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 13:50:41 by alidy       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

typedef struct	s_flags
{
	int			zero;
	int			point;
	int			neg;
	int			width;
	int			precision;
	char		c;
}				t_flags;
void			write_flags(int zero, int c, int flag, int nb);
void			write_justify_flags(int zero, char *numb, int size, int nb);
char			*ft_fstrjoin(char *s1, char *s2);
unsigned int	ft_longlen(unsigned int nb);
char			*get_str_format
(const char *s, int *i, va_list list, t_flags *tab);
void			parsing_flags(t_flags *tab, char *str);
t_flags			init_struct(void);
int				int_format(t_flags tab, int nb);
int				char_format(t_flags tab, char c);
int				str_format(t_flags tab, char *str);
int				ft_printf
(const char *format, ...) __attribute__((format(printf,1,2)));
char			*ft_itoa_base(int nb, char *base);
char			*ft_ullitoa_base(unsigned long long nb, char *base);
void			ft_strtoupper(char **str);
void			write_space(int c);
int				hexa_format(t_flags tab, char *nb);
int				un_format(t_flags tab, unsigned int nb);

#endif
