/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:45:23 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/14 21:33:58 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	main(int ac, char **av)
{
	if (ft_select_init(ac) == -1)
		return (1);
	if (!av)
		return (1);
	handle_signal(0);
	cmdput("ti");
	cmdput("cl");
	render();
	listen_keystroke();
	return (0);
}
