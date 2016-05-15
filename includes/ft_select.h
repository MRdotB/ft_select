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
# define CHT 0x09 //\t
# define DEL 0x7F //DEL
# define LEF 0x445B1B //left
# define RIG 0x435B1B //right
# define UPP 0x415B1B //up
# define DOW 0x425B1B //down
# define CLEF 0x44353B315B1B //CTRL left
# define CRIG 0x43353B315B1B //CTRL up
# define CUPP 0x41353B315B1B //CTRL right
# define CDOW 0x42353B315B1B //CTRL down
# define END 0x464F1B //end
# define HOM 0x484F1B //home
# define ESC 0x1B // esc
# define NUL 0x00 //\0

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
void	listen_keystroke(void);

void	catch_signal(void);
void	handle_signal(int sig);

void	term_setup(struct termios **config);
void	term_restore(struct termios **config);

void	term_clear(void);
int		termsize(int xy);

void	cmdput(char *area);
int		cmdgoto(int x, int y);

void	render(t_dlist *head);

#endif
