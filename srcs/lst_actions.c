/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:52:34 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/26 12:49:24 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	lst_free_one(t_dlist *lst)
{
	free(((t_slt_el*)lst->content)->str);
	free(lst->content);
	free(lst);
	lst = NULL;
}

void	lst_del_one(t_dlist **lst)
{
	t_dlist	*to_del;

	to_del = *lst;
	if ((*lst)->prev != *lst && (*lst)->next != *lst)
	{
		if (((t_slt_el*)(*lst)->content)->first)
			((t_slt_el*)(*lst)->next->content)->first = 1;
		(*lst)->prev->next = (*lst)->next;
		(*lst)->next->prev = (*lst)->prev;
		lst_move_right(lst);
	}
	else
	{
		lst_free_one(to_del);
		handle_signal(0);
	}
	lst_free_one(to_del);
}

void	validate_render(t_dlist *lst)
{
	int	count;
	int	i;
	int flag;

	flag = 0;
	count = ft_dlstcount(lst);
	i = 1;
	while (i < count)
	{
		if ((((t_slt_el*)lst->content)->selected) == 1)
		{
			if (flag)
				ft_putchar(' ');
			ft_putstr_fd(((t_slt_el*)lst->content)->str, isatty(STDOUT_FILENO));
			flag = 1;
		}
		i++;
		lst = lst->next;
	}
	ft_putchar('\n');
}

void	lst_validate(t_dlist **lst)
{
	if (*lst)
		handle_signal(1337);
}
