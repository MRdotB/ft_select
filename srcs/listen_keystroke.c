/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_keystroke.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:02:22 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/26 14:49:10 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_chrmatch(char *str)
{
	static ssize_t	match[] = {CLF, SUP, DEL, LEF, RIG, UPP, DOW, SPA, ESC,
		NUL};
	int				i;

	i = 0;
	while (match[i])
	{
		if (((ssize_t *)(str))[0] == match[i])
			return (i);
		i++;
	}
	return (9);
}

static t_dlist	*find_first(t_dlist **lst)
{
	t_dlist	*cpy;

	cpy = *lst;
	while (cpy)
	{
		if ((((t_slt_el*)cpy->content)->first) == 1)
			return (cpy);
		cpy = cpy->next;
	}
	return (NULL);
}

static void		lst_void_ret(t_dlist **lst)
{
	if (*lst)
		return ;
	return ;
}

static void		lst_esc(t_dlist **lst)
{
	if (*lst)
		handle_signal(0);
	handle_signal(0);
}

void			listen_keystroke(t_dlist **lst)
{
	char		buffer[8];
	int			el;
	static void	(*f[])(t_dlist **lst) = { lst_validate, lst_del_one,
		lst_del_one, lst_move_left, lst_move_right, lst_move_up,
		lst_move_down, lst_select, lst_esc, lst_void_ret};

	ft_memset(buffer, 0, 8);
	while (read(0, buffer, 8) != -1)
	{
		el = ft_chrmatch(buffer);
		f[el](lst);
		render(find_first(lst), 0);
		ft_memset(buffer, 0, 8);
	}
}
