/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 20:53:05 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/14 21:41:39 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	term_setup(struct termios **config)
{
	struct termios	new;

	if (!(*config = (struct termios *)malloc(sizeof(struct termios))))
		return ;
	tcgetattr(STDIN_FILENO, *config);
	new = **config;
	new.c_iflag |= IGNBRK;
	new.c_lflag |= ISIG;
	new.c_lflag &= ~(ICANON | ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
}

void	term_restore(struct termios **config)
{
	char	cp[3];

	term_clear();
	cmdgoto(0, 0);
	cmdput("ve");
	tcsetattr(STDIN_FILENO, TCSANOW, *config);
	signal(SIGTSTP, SIG_DFL);
	cp[0] = (*config)->c_cc[VSUSP];
	cp[1] = '\n';
	cp[2] = '\0';
	ioctl(isatty(STDOUT_FILENO), TIOCSTI, &cp);
	free(*config);
	*config = NULL;
}

void	term_clear(void)
{
	int	i;

	i = termsize(1);
	while (--i >= 0)
	{
		cmdgoto(0, i);
		cmdput("dl");
	}
}

int		termsize(int xy)
{
	int				ret;
	struct winsize	win;

	ret = 0;
	if (!ioctl(STDIN_FILENO, TIOCGWINSZ, &win))
		ret = (xy) ? win.ws_row : win.ws_col;
	return (ret);
}
