# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrosie <mrosie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 12:55:51 by mrosie            #+#    #+#              #
#    Updated: 2020/11/24 15:12:54 by mrosie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c \
			ft_memchr.c \
			ft_putchar_fd.c \
			ft_strchr.c \
			ft_strlen.c \
			ft_strtrim.c \
			ft_atoi.c \
			ft_isascii.c \
			ft_memcmp.c \
			ft_putendl_fd.c \
			ft_strdup.c \
			ft_substr.c \
			ft_bzero.c \
			ft_isdigit.c \
			ft_memcpy.c \
			ft_putnbr_fd.c \
			ft_strjoin.c \
			ft_strncmp.c \
			ft_tolower.c \
			ft_calloc.c \
			ft_isprint.c \
			ft_memmove.c \
			ft_putstr_fd.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_toupper.c \
			ft_isalnum.c \
			ft_itoa.c \
			ft_memccpy.c \
			ft_memset.c \
			ft_split.c \
			ft_strlcpy.c \
			ft_strrchr.c \
			ft_strmapi.c

BONUS_SRCS	= ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c

HEAD	= libft.h

OBJS	= $(SRCS:.c=.o)

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

CFLAG	= -Wall -Werror -Wextra

CC		= gcc

RM		= rm -f

NAME	= libft.a

all:	$(NAME)

.c.o:
	@ $(CC) $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(HEAD)
	@ ar rc $(NAME) $(OBJS)

bonus:	$(BONUS_OBJS) $(OBJS) $(HEAD)
	@ ar rc $(NAME) $(BONUS_OBJS) $(OBJS)

clean:
	@ $(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	@ $(RM) $(NAME)

re:	fclean all

.PHONY:	clean fclean re all bonus
