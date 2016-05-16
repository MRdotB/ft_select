/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slt_elm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 22:21:13 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/16 18:44:01 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_slt_el	create_entry(char *str)
{
	t_slt_el el;

	el.str = ft_strdup(str);
	el.selected = 0;
	el.current = 0;
	return (el);
}

void			entry_init(t_dlist **head, char **av)
{
	t_slt_el	el;

	while (*av)
	{
		el = create_entry(*av);
		ft_dlstpush(head, ft_dlstnew(&el, sizeof(&el))); 
		av++;
	}
}
