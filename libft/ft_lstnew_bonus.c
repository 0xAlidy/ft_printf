/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alidy <alidy@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 11:14:14 by alidy        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 11:13:43 by alidy       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*maillon;

	if (!(maillon = malloc(sizeof(t_list))))
		return (0);
	maillon->content = content;
	maillon->next = 0;
	return (maillon);
}
