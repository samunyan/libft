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
INCDIR			=	.
PRINTFDIR		= ft_printf

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
            ft_putnbr_fd.c \
            ft_s_lstnew.c \
			ft_s_lstadd_front.c \
			ft_s_lstsize.c \
			ft_s_lstlast.c \
			ft_s_lstadd_back.c \
			ft_s_lstdelone.c \
			ft_s_lstclear.c \
			ft_s_lstiter.c \
			ft_s_lstmap.c \
			ft_s_lstfind_content.c \
			ft_s_lstfind_position.c \
			ft_isspace.c \
			ft_skip_space.c \
			ft_islower.c \
			ft_isupper.c \
			ft_free_arr_until.c \
			ft_strndup.c \
			ft_append.c \
			ft_strnjoin.c \
			ft_ultoa_base.c \
			ft_prepend.c \
			ft_memappend.c \
			ft_strupcase.c \
			ft_strcmp.c \
			ft_get_next_line.c \
			ft_max.c \
			ft_min.c \
			ft_lis.c \
			ft_abs.c \
			ft_binary_search.c \
			ft_insertion_sort.c \
			ft_quicksort.c \
			ft_selection_sort.c \
			ft_swap.c
OBJS	=	$(SRCS:.c=.o)
INCS	=	-I $(INCDIR)

#Libs
LIBFTPRINTF = $(PRINTFDIR)/libftprintf.a

#Compiler
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
ifeq ($(DEBUG), 1)
	CFLAGS	+=	-g
	ifeq ($(SAN), 1)
		CFLAGS	+=	-fsanitize=address
	endif
endif

.PHONY:		all clean fclean re FORCE

all:		$(NAME)

$(NAME):	$(OBJS)
			cp $(LIBFTPRINTF) $(NAME)
			ar rcs $(NAME) $(OBJS)

%.o:%.c		$(LIBFTPRINTF)
			$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(LIBFTPRINTF):	FORCE
		make -C $(PRINTFDIR)

FORCE:

clean:
			rm -f $(OBJS)
			make clean -C $(PRINTFDIR)

fclean:		clean
			rm -f $(NAME)
			make fclean -C $(PRINTFDIR)

re:			fclean all
