/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_keystroke.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:02:22 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/16 00:13:35 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_chrmatch(char *str)
{
	static ssize_t	match[] = {CLF, SUP, CHT, DEL, LEF, RIG, UPP, DOW, CLEF, CRIG, CUPP, CDOW, END, HOM, ESC, NUL};
	int	i;

	i = 0;
	printf("\nbuf = %lx\n", ((ssize_t *)(str))[0]);
	while (match[i])
	{
//		printf("\nmatch = %lx\n", match[i]);
		if (((ssize_t *)(str))[0] == match[i])
			return (i);
		i++;
	}
	return (0);
}

int	my_outc(int c)
{
	return write(1, &c, 1);
}


void	listen_keystroke(t_dlist *lst)
{
	char	buffer[8];
	int		el;
	char	*touche[] = {"CLF", "SUP", "CHT", "DEL", "le", "nd", "up", "do", "le", "CRIG", "CUPP", "CDOW", "END", "HOM", "ESC", "NUL"};

	ft_memset(buffer, 0, 8);
	while (read(0, buffer, 8) != -1)
	{
		el = ft_chrmatch(buffer);
		if (ft_strcmp("ESC", touche[el]) == 0)
		{
			exit(0);
		}
		term_clear();
		render(lst);
		ft_putendl(touche[el]);
		ft_memset(buffer, 0, 8);
	}
}
