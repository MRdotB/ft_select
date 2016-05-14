# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 16:21:36 by bchaleil          #+#    #+#              #
#    Updated: 2016/05/14 21:39:41 by bchaleil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc
NAME			=	ft_select
FLAGS			=	-Wall -Werror -Wextra -g
LIB_PATH		=	libft/
LIB				=	$(LIB_PATH)libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft
INCLUDES		=	-I ./includes -I ./libft/includes
SRCS			=	srcs/main.c srcs/errors.c srcs/ft_select_init.c\
					srcs/signal.c srcs/listen_keystroke.c srcs/term.c\
					srcs/termcaps_wrap.c srcs/render.c srcs/termsize.c\
					srcs/term_clear.c

OBJS			=	$(SRCS:srcs/%.c=obj/%.o)

all: obj $(NAME)

$(LIB):
	@make -C $(LIB_PATH)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(FLAGS) -o $@ $^ -lncurses -lm

obj:
	@mkdir -p obj

obj/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean

re: fclean all

.PHONY:clean fclean re
