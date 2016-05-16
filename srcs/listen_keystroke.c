/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_keystroke.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:02:22 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/16 21:59:46 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_chrmatch(char *str)
{
	static ssize_t	match[] = {CLF, SUP, DEL, LEF, RIG, UPP, DOW, SPA, ESC, NUL};
	int	i;

	i = 0;
//	printf("\nbuf = %lx\n", ((ssize_t *)(str))[0]);
	while (match[i])
	{
//		printf("\nmatch = %lx\n", match[i]);
		if (((ssize_t *)(str))[0] == match[i])
			return (i);
		i++;
	}
	return (0);
}

void	listen_keystroke(t_dlist **lst, t_dlist *head)
{
	char	buffer[8];
	int		el;
	char	*touche[] = {"CLF", "SUP", "DEL", "LEF", "RIG", "UPP", "DOW", "SPA", "ESC", "NUL"};
	static void (*f[])(t_dlist **lst) = { lst_move_up, lst_move_up, lst_move_up, lst_move_left,
		lst_move_right, lst_move_up, lst_move_down, lst_select, lst_move_down, lst_move_down};
	ft_memset(buffer, 0, 8);
	while (read(0, buffer, 8) != -1)
	{
		el = ft_chrmatch(buffer);
		if (ft_strcmp("ESC", touche[el]) == 0)
		{
			handle_signal(0);
		}
		term_clear();
		f[el](lst);
		render(head, 0);
//		ft_putendl(touche[el]);
		ft_memset(buffer, 0, 8);
	}
}
