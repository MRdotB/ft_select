/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 14:19:19 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/16 21:46:16 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	lst_move_right(t_dlist **lst)
{
	((t_slt_el*)(*lst)->content)->current = 0;
	*lst = (*lst)->next;
	((t_slt_el*)(*lst)->content)->current = 1;
}

void	lst_move_left(t_dlist **lst)
{
	((t_slt_el*)(*lst)->content)->current = 0;
	*lst = (*lst)->prev;
	((t_slt_el*)(*lst)->content)->current = 1;
}

void	lst_move_down(t_dlist **lst)
{
	int x;
	t_slt_el	*el;

	x = ((t_slt_el*)(*lst)->content)->x;
	((t_slt_el*)(*lst)->content)->current = 0;
	*lst = (*lst)->next;
	while (*lst)
	{
		el = (t_slt_el*)(*lst)->content;
		if (el->x == x)
			break ;
		*lst = (*lst)->next;
	}
	((t_slt_el*)(*lst)->content)->current = 1;
}

void	lst_move_up(t_dlist **lst)
{
	int x;
	t_slt_el	*el;

	x = ((t_slt_el*)(*lst)->content)->x;
	((t_slt_el*)(*lst)->content)->current = 0;
	*lst = (*lst)->prev;
	while (*lst)
	{
		el = (t_slt_el*)(*lst)->content;
		if (el->x == x)
			break ;
		*lst = (*lst)->prev;
	}
	((t_slt_el*)(*lst)->content)->current = 1;
}

void	lst_select(t_dlist **lst)
{
	if (((t_slt_el*)(*lst)->content)->selected == 1)
		((t_slt_el*)(*lst)->content)->selected = 0;
	else
		((t_slt_el*)(*lst)->content)->selected = 1;
	lst_move_right(lst);
}
