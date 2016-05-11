#include "ft_select.h"

static int		ft_chrmatch(char *str)
{
	static ssize_t	match[] = {CLF, SUP, CHT, DEL, LEF, RIG, UPP, DOW, CLEF, CRIG, CUPP, CDOW, END, HOM, ESC, NUL};
	int	i;

	i = 0;
	printf("\nbuf = %lx\n", ((ssize_t *)(str))[0]);
	while (match[i])
	{
//		printf("\nmatch = %lx\n", match[i]);
		if (((ssize_t *)(str))[0] == match[i])
			return (i);
		i++;
	}
	return (0);
}

int	my_outc(int c)
{
	return write(1, &c, 1);
}

int	voir_touche(void)
{
	char	buffer[8];
	struct termios	term;
	int		el;
	char	*res;
	char	*touche[] = {"CLF", "SUP", "CHT", "DEL", "le", "nd", "up", "do", "le", "CRIG", "CUPP", "CDOW", "END", "HOM", "ESC", "NUL"};

	ft_memset(buffer, 0, 8);
	while (read(0, buffer, 8) != -1)
	{
		el = ft_chrmatch(buffer);
		//ft_putendl(touche[el]);
		if ((res = tgetstr(touche[el], NULL)) == NULL)
			return (-1);
		tputs(res, 0, my_outc);
		ft_memset(buffer, 0, 8);
	}
	if (tcgetattr(0, &term) == -1)
		return (-1);
	// remet le term par default
	term.c_lflag = (ICANON | ECHO);
	if(tcsetattr(0, 0, &term) == -1)
		return (-1);
	return (0);
}

int              main(void)
{
	char	*name_term;
	struct	termios term;
 
	if((name_term = getenv("TERM")) == NULL)
		return (-1);
	if(tgetent(NULL, name_term) == -1)
		return (-1);
	if(tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
		voir_touche();
	return (0);
}
