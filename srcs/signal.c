/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 21:39:15 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/16 00:14:12 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	catch_signal(void)
{
//	MAC
//	signal(SIGEMT, handle_signal);
	signal(SIGHUP, handle_signal);
	signal(SIGQUIT, handle_signal);
	signal(SIGINT, handle_signal);
	signal(SIGBUS, handle_signal);
	signal(SIGFPE, handle_signal);
	signal(SIGSYS, handle_signal);
	signal(SIGABRT, handle_signal);
	signal(SIGALRM, handle_signal);
	signal(SIGCONT, handle_signal);
	signal(SIGPIPE, SIG_DFL);
//	signal(SIGSEGV, handle_signal);
	signal(SIGTERM, handle_signal);
	signal(SIGTTOU, handle_signal);
	signal(SIGTSTP, handle_signal);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	signal(SIGXCPU, handle_signal);
	signal(SIGXFSZ, handle_signal);
	signal(SIGWINCH, handle_signal);
}

void		handle_signal(int sig)
{
	static struct termios	*config;

	if (config == NULL)
	{
		catch_signal();
		cmdput("vi");
		term_setup(&config);
	}
	else if (sig == SIGTSTP)
		term_restore(&config);
	else if (sig == SIGCONT)
		ft_putendl("sigcount ctrl z");
	else if (sig == SIGWINCH)
		ft_putendl("resize");
	else
	{
//	DEBUG
//		ft_putnbrnl(sig);
		cmdput("ve");
		cmdput("te");
		tcsetattr(STDIN_FILENO, TCSANOW, config);
		free(config);
		if (sig != -1)
			exit(0);
	}
}
