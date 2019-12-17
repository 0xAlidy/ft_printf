/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alidy <alidy@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 00:53:29 by alidy        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 13:46:39 by alidy       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		complete_pointer(t_flags tab, va_list lst)
{
	char	*temp;
	int		res;

	temp = ft_ullitoa_base((intptr_t)va_arg(lst, void *), "0123456789abcdef");
	if (tab.point == 1 && tab.precision <= 0 && ft_memcmp("0", temp, 1) == 0)
	{
		free(temp);
		temp = ft_strdup("");
	}
	temp = ft_fstrjoin(ft_strdup("0x"), temp);
	res = hexa_format(tab, temp);
	return (res);
}

int		complete_str(t_flags tab, va_list lst)
{
	int		res;
	char	*temp;

	temp = 0;
	if (tab.c == 'd' || tab.c == 'i')
		res = int_format(tab, va_arg(lst, int));
	else if (tab.c == 'c')
		res = char_format(tab, (char)va_arg(lst, int));
	else if (tab.c == 'u')
		res = un_format(tab, va_arg(lst, unsigned int));
	else if (tab.c == 'p')
		res = complete_pointer(tab, lst);
	else if (tab.c == 'x' || tab.c == 'X')
	{
		temp = ft_itoa_base(va_arg(lst, int), "0123456789abcdef");
		if (tab.c == 'X')
			ft_strtoupper(&temp);
		res = hexa_format(tab, temp);
	}
	else if (tab.c == 's')
		res = str_format(tab, va_arg(lst, char *));
	else
		res = char_format(tab, '%');
	return (res);
}

int		printf_format(const char *str, int *i, va_list lst)
{
	char	*temp;
	int		res;
	t_flags	tab;

	tab = init_struct();
	temp = get_str_format(str, i, lst, &tab);
	parsing_flags(&tab, temp);
	res = complete_str(tab, lst);
	free(temp);
	return (res);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	va_list	list;

	i = 0;
	res = 0;
	va_start(list, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			res += printf_format(str, &i, list);
		}
		else
		{
			write(1, &str[i], 1);
			res++;
		}
		i++;
	}
	va_end(list);
	return (res);
}
