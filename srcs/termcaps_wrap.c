/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_wrap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 22:13:51 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/26 14:10:33 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	cmdput(char *area)
{
	char	*ptr;

	if ((ptr = tgetstr(area, NULL)) != NULL)
		ft_putstr_fd(ptr, isatty(STDOUT_FILENO));
	return ;
}

void	cmdgoto(int x, int y)
{
	char	*ptr;
	char	*ptr2;

	if ((ptr = tgetstr("cm", NULL)) != NULL)
		if ((ptr2 = tgoto(ptr, x, y)) != NULL)
			ft_putstr_fd(ptr2, isatty(STDOUT_FILENO));
}
