# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 16:52:55 by jkosaka           #+#    #+#              #
#    Updated: 2023/04/30 15:57:51 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libutil.a

HEADERFILE := ../includes/utils.h

SRCS := ./*.c

OBJS := $(SRCS:.c=.o)

LIBFT := ../libft/libft.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	make -C ../libft
	cp $(LIBFT) $(NAME)
	ar rc $@ $^

all	: $(NAME)

%.o : %.c $(HEADERFILE)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C ../libft
	$(RM) $(OBJS)

fclean : clean
	make fclean -C ../libft
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus