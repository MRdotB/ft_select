/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slt_elm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 22:21:13 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/26 14:05:37 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_slt_el	*create_entry(char *str)
{
	t_slt_el	*el;

	if (!(el = ft_memalloc(sizeof(*el))))
		return (NULL);
	el->str = ft_strdup(str);
	el->selected = 0;
	el->current = 0;
	el->x = 0;
	el->y = 0;
	el->first = 0;
	return (el);
}

void			entry_init(t_dlist **head, char **av)
{
	t_slt_el	*data;
	t_dlist		*lst;

	while (*av != NULL)
	{
		data = create_entry(*av);
		lst = ft_dlstnew(data, sizeof(data));
		ft_dlstpush(head, lst);
		av++;
	}
}
