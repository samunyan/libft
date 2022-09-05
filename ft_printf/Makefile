# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 13:27:42 by samunyan          #+#    #+#              #
#    Updated: 2022/04/12 13:27:43 by samunyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

#Directories
INCDIR	=	.

#Files
SRCS	=	ft_printf.c \
			ft_parse_format.c \
			ft_get_spec.c \
			ft_convert_diux.c \
			ft_convert_scp.c \
			ft_convert_percent.c \
			ft_helpers_1.c \
			ft_helpers_2.c
OBJS	=	$(SRCS:.c=.o)
INCS	=	$(addprefix -I ,$(INCDIR))

#Compiler
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
ifneq ($(filter 1,$(SAN)),)
	CFLAGS	+=	-g
	ifeq ($(SAN), 1)
		CFLAGS	+=	-fsanitize=address
	endif
endif

.PHONY:		all  clean fclean re san

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o:%.c
			$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

san:
			@SAN=1 make re
