/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 21:39:15 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/25 16:44:45 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	catch_signal(void)
{
	signal(SIGTSTP, handle_signal);
	signal(SIGCONT, handle_signal);
	signal(SIGTERM, handle_signal);
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
	signal(SIGWINCH, handle_signal);
}

void		handle_signal(int sig)
{
	static struct termios	*config;

	if (config == NULL || sig == SIGTSTP || sig == SIGCONT)
	{
		term_setup(&config);
		if (sig == SIGTSTP)
			term_restore(&config);
		else if (sig == SIGCONT)
		{
			term_setup(&config);
			term_clear();
			render(NULL, 1);
		}
	}
	else if (sig == SIGWINCH)
	{
		term_clear();
		render(NULL, 1);
	}
	else
	{
		cmdput("ve");
		cmdput("te");
		tcsetattr(STDIN_FILENO, TCSANOW, config);
		free(config);
		if (sig != -1)
			exit(0);
	}
}
