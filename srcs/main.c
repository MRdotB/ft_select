/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:45:23 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/16 21:58:55 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

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
	render(head, 0);
	listen_keystroke(&head, head);
	return (0);
}
