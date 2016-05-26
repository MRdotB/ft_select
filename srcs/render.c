/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 22:46:14 by bchaleil          #+#    #+#             */
/*   Updated: 2016/05/26 15:50:46 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	f_biggest(t_dlist *lst)
{
	int	ret;
	int len;
	int	count;
	int	i;

	count = ft_dlstcount(lst);
	i = 1;
	ret = 0;
	while (i < count)
	{
		len = ft_strlen(((t_slt_el*)lst->content)->str);
		if (len > ret)
			ret = len;
		lst = lst->next;
		i++;
	}
	return (ret);
}

static int	fit_in_term(t_dlist *head, int biggest, int w, int h)
{
	int	per_col;

	if (biggest > w)
		return (0);
	per_col = w / (biggest + 3);
	if (!per_col || ((ft_dlstcount(head) / per_col) > h))
		return (0);
	else
		return (1);
}

static void	display_el(t_dlist *lst)
{
	char	*str;
	int		len;

	str = ((t_slt_el*)lst->content)->str;
	len = ft_strlen(str) - 1;
	if (((t_slt_el*)lst->content)->current == 1)
		cmdput("us");
	if (((t_slt_el*)lst->content)->selected == 1)
		cmdput("mr");
	if (str[len] == 'c' && str[len - 1] == '.')
		ft_putstr_fd(GREEN, isatty(STDOUT_FILENO));
	else if (str[len] == 'o' && str[len - 1] == '.')
		ft_putstr_fd(YELLOW, isatty(STDOUT_FILENO));
	else
		ft_putstr_fd(CYAN, isatty(STDOUT_FILENO));
	ft_putstr_fd(((t_slt_el*)lst->content)->str, isatty(STDOUT_FILENO));
	cmdput("me");
}

static void	display(t_dlist *lst, int biggest, int w)
{
	int	per_col;
	int	x;
	int	y;
	int	count;
	int	i;

	count = ft_dlstcount(lst);
	i = 1;
	per_col = w / (biggest + 3);
	y = 0;
	x = 0;
	while (i < count)
	{
		if (x < per_col)
			cmdgoto(x++ * (biggest + 3), y);
		else
		{
			x = 0;
			cmdgoto(x++ * (biggest + 3), ++y);
		}
		display_el(lst);
		i++;
		((t_slt_el*)lst->content)->x = x * (biggest + 3);
		lst = lst->next;
	}
}

void		render(t_dlist *lst, int hacky)
{
	static t_dlist	*head;
	int				biggest;
	int				w;
	int				h;

	if (hacky == 1337)
		return (validate_render(head));
	term_clear();
	if (hacky == 0)
		head = lst;
	biggest = f_biggest(head);
	w = termsize(0);
	h = termsize(1);
	if (fit_in_term(head, biggest, w, h) == 0)
	{
		term_clear();
		return (ft_putstr_fd("Terminal is too tiny !", isatty(STDOUT_FILENO)));
	}
	display(head, biggest, w);
}
