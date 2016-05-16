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

# define CLF 0x0A //\n
# define SUP 0x7E335B1B //sup
# define DEL 0x7F //DEL
# define LEF 0x445B1B //left
# define RIG 0x435B1B //right
# define UPP 0x415B1B //up
# define DOW 0x425B1B //down
# define SPA ' ' // space
# define ESC 0x1B // esc
# define NUL 0x00 // \0

struct		s_slt_el
{
	char	*str;
	int		selected;
	int		current;
	int		x;
	int		y;
};

typedef struct s_slt_el	t_slt_el;

int		ft_select_init(int ac);
void	entry_init(t_dlist **head, char **av);
void	bc_error(char *error_msg);
void	listen_keystroke(t_dlist **lst, t_dlist *head);

void	catch_signal(void);
void	handle_signal(int sig);

void	term_setup(struct termios **config);
void	term_restore(struct termios **config);

void	term_clear(void);
int		termsize(int xy);

void	cmdput(char *area);
int		cmdgoto(int x, int y);

void	lst_move_right(t_dlist **lst);
void	lst_move_left(t_dlist **lst);
void	lst_move_down(t_dlist **lst);
void	lst_move_up(t_dlist **lst);
void	lst_select(t_dlist **lst);

int		f_biggest(t_dlist *lst);
void	render(t_dlist *lst, int hacky);

int	col_number(t_dlist *head);
#endif
