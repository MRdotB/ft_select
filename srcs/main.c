/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:45:23 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/25 16:23:46 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	main(int ac, char **av)
{
	t_dlist	*head;

	head = NULL;
	if (ft_select_init(ac) == -1)
		return (1);
	entry_init(&head, av + 1);
	handle_signal(0);
	cmdput("ti");
	cmdput("cl");
	((t_slt_el*)head->content)->current = 1;
	render(head, 0);
	listen_keystroke(&head, head);
	return (0);
}
