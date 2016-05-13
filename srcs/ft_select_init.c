/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 17:17:24 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/13 18:14:43 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	ft_select_init(int ac)
{
	char	*name_term;

	if ((name_term = getenv("TERM")) == NULL)
	{
		bc_error("No terminal type specified in env.");
		return (-1);
	}
	if ((tgetent(NULL, name_term)) != 1)
	{
		bc_error("Termcap database not found.");
		return (-1);
	}
	if (ac < 2)
	{
		bc_error("ft_select: not enought arguments.");
		return (-1);
	}
	return (1);
}
