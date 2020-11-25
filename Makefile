# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrosie <mrosie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 13:26:38 by mrosie            #+#    #+#              #
#    Updated: 2020/11/25 16:09:44 by mrosie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c \
			ft_processor.c \
			ft_parser.c \
			ft_print_char.c \
			ft_print_string.c \
			ft_print_number.c \
			ft_print_pointer.c \
			ft_itoa_base.c \
			ft_ulitoa_base.c \
			
HEAD	= ft_printf.h

OBJS	= $(SRCS:.c=.o)

CFLAG	= -Wall -Werror -Wextra

CC		= gcc

RM		= rm -f

NAME	= libftprintf.a

all:	$(NAME)

.c.o:
	@ $(CC) $(CFLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(HEAD)
	@ $(MAKE) -C ./Libft
	@ cp ./Libft/libft.a $(NAME)
	@ ar rc $(NAME) $(OBJS)

clean:
	@ $(MAKE) clean -C ./Libft
	@ $(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	@ $(MAKE) fclean -C ./Libft
	@ $(RM) $(NAME)

re:	fclean all
	@ $(MAKE) re -C ./Libft

.PHONY:	clean fclean re all
