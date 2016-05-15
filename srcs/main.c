/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:45:23 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/15 23:13:03 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	checkcontent(t_dlist *el)
{
	ft_putendl(((t_slt_el*)el->content)->str);
	ft_putnbrnl(ft_strlen(((t_slt_el*)el->content)->str));
	ft_putnbrnl(((t_slt_el*)el->content)->x);
	ft_putnbrnl(((t_slt_el*)el->content)->y);
}

int	main(int ac, char **av)
{
	t_dlist		*head;

	head = NULL;
	if (ft_select_init(ac) == -1)
		return (1);
	entry_init(&head, av + 1);
	handle_signal(0);
	cmdput("ti");
	cmdput("cl");
	render(head);
	listen_keystroke();
	return (0);
}
