/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 12:59:06 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/26 16:06:28 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"

# include <termios.h>
# include <term.h>
# include <stdio.h>
# include <signal.h>
# include <sys/ioctl.h>

# ifdef __unix__
#  include <linux/limits.h>
# elif defined __APPLE__
#  include <sys/syslimits.h>
# endif

# define CLF 0x0A
# define SUP 0x7E335B1B
# define DEL 0x7F
# define LEF 0x445B1B
# define RIG 0x435B1B
# define UPP 0x415B1B
# define DOW 0x425B1B
# define SPA ' '
# define ESC 0x1B
# define NUL 0x00

typedef struct	s_slt_el
{
	char		*str;
	int			selected;
	int			current;
	int			x;
	int			first;
}				t_slt_el;

int				ft_select_init(int ac);
void			entry_init(t_dlist **head, char **av);
void			bc_error(char *error_msg);
void			listen_keystroke(t_dlist **lst);

void			catch_signal(void);
void			handle_signal(int sig);

void			term_setup(struct termios **config, int sig);
void			term_restore(struct termios **config);

void			term_clear(void);
int				termsize(int xy);

void			cmdput(char *area);
void			cmdgoto(int x, int y);

void			lst_move_right(t_dlist **lst);
void			lst_move_left(t_dlist **lst);
void			lst_move_down(t_dlist **lst);
void			lst_move_up(t_dlist **lst);
void			lst_select(t_dlist **lst);
void			lst_del_one(t_dlist **lst);
void			validate_render(t_dlist *lst);
void			lst_validate(t_dlist **lst);

void			render(t_dlist *lst, int hacky);

#endif
