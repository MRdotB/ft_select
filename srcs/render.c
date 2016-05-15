/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 22:46:14 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/16 00:15:27 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	f_biggest(t_dlist *lst)
{
	int	ret;
	int len;

	lst->prev->next = NULL;
	ret = 0;
	while (lst)
	{
		len = ft_strlen(((t_slt_el*)lst->content)->str);
		if (len > ret)
			ret = len;
		lst = lst->next;
	}
	return (ret);
}

int		fit_in_term(t_dlist	*head, int biggest, int w, int h)
{
	int	per_col;

	if (biggest > w)
		return (0);
	per_col = w / (biggest + 3);
	if ((ft_dlstcount(head) / per_col) > h)
		return (0);
	else
		return (1);
}

void	display(t_dlist *lst, int biggest, int w)
{
	int	per_col;
	int	x;
	int	y;

	lst->prev->next = NULL;
	per_col = w / (biggest + 3);
	y = 0;
	x = 0;
	while (lst)
	{
		if (x < per_col)
		{
			cmdgoto(x * (biggest + 3), y);
			x++;
		}
		else
		{
			x = 0;
			y++;
			cmdgoto(x * (biggest + 3), y);
		}
//		if (((t_slt_el*)lst->content)->selected)
//			ft_putstr("\e[7m");
//		if (((t_slt_el*)lst->content)->current)
//			ft_putstr("\e[4m");
		ft_putstr(((t_slt_el*)lst->content)->str);
		ft_putstr("\e[0m");
		lst = lst->next;
	}
}

void	render(t_dlist *head)
{
	int	biggest; 
	int	w;
	int	h;

	biggest = f_biggest(head);
	w = termsize(0);
	h = termsize(1);
//	printf("w= %d, h= %d, biggest= %d", w, h, biggest);
//	printf("per col= %d", w / (biggest + 3));
	if (fit_in_term(head, biggest, w, h) == 0)
		return (ft_putstr("Terminal is too tiny !"));
	display(head, biggest, w);
}
