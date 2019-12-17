/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hexa_format.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alidy <alidy@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 03:57:41 by alidy        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 13:46:47 by alidy       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	test_hexa(char **nb, int precision, int *size)
{
	if (!ft_memcmp("", (*nb), 1) && precision != 0)
	{
		free(*nb);
		(*nb) = ft_strdup("0");
	}
	*size = ft_strlen(*nb);
}

int		hexa_format(t_flags tab, char *nb)
{
	int		size;
	int		c;
	int		zero;
	int		res;

	zero = 0;
	c = 0;
	test_hexa(&nb, tab.precision, &size);
	if (tab.precision - size > 0)
		zero = tab.precision - size;
	if (tab.width - size - zero > 0)
		c = tab.width - size - zero;
	res = size + zero + c;
	if (tab.neg == 0)
	{
		write_flags(zero, c, tab.zero, 1);
		nb < 0 ? write(1, nb + 1, size - 1) : write(1, nb, size);
	}
	else
	{
		write_justify_flags(zero, nb, size, 1);
		write_space(c);
	}
	free(nb);
	return (res);
}
