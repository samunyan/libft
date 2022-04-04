# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 13:28:03 by samunyan          #+#    #+#              #
#    Updated: 2022/04/04 13:28:06 by samunyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

#Directories
INCDIR	=	.

#Files
SRCS	=	ft_atoi.c \
            ft_bzero.c \
            ft_calloc.c \
            ft_isalnum.c \
            ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isprint.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_memcpy.c \
            ft_memmove.c \
            ft_memset.c \
            ft_strchr.c \
            ft_strdup.c \
            ft_strlcat.c \
            ft_strlcpy.c \
            ft_strlen.c \
            ft_strnstr.c \
            ft_strncmp.c\
            ft_strrchr.c \
            ft_tolower.c \
            ft_toupper.c \
            ft_calloc.c \
            ft_strdup.c \
            ft_substr.c \
            ft_strjoin.c \
            ft_strtrim.c \
            ft_split.c \
            ft_itoa.c \
            ft_strmapi.c \
            ft_striteri.c \
            ft_putchar_fd.c \
            ft_putstr_fd.c \
            ft_putendl_fd.c \
            ft_putnbr_fd.c
B_SRCS	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c
OBJS	=	$(SRCS:.c=.o)
B_OBJS	=	$(B_SRCS:.c=.o)
ifdef BONUS
	OBJFILES = $(OBJS) $(B_OBJS)
else
	OBJFILES = $(OBJS)
endif

INCS	=	-I $(INCDIR)

#Compiler
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

.PHONY:		all clean fclean re bonus

all:		$(NAME)

$(NAME):	$(OBJFILES)
			ar rcs $(NAME) $(OBJFILES)

%.o:%.c
			$(CC) $(CFLAGS) $(INCS) -c $< -o $@


bonus:
			make BONUS=1 all

clean:
			rm -f $(OBJS) $(B_OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
