NAME		:= miniRT

SRCROOT		:= src
SRCDIRS		:= $(shell find $(SRCROOT) -type d)
SRCS		:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c)) # TODO

OBJROOT		:= obj
OBJDIRS		:= $(patsubst $(SRCROOT)/%, $(OBJROOT)/%, $(SRCDIRS))
OBJS		:= $(patsubst $(SRCROOT)/%, $(OBJROOT)/%, $(SRCS:.c=.o))

DEPS		:= $(OBJS:.o=.d)

INCDIRS		:= includes
INCLUDE		:= $(addprefix -I, $(INCDIRS))

MLX := ./minilibx-linux/libmlx.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror # -MMD -MP # -g -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJS)
	make -C ../utils
	make -C ./minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBUTIL) $(MLX) -lXext -lX11 -lm

$(OBJROOT)/%.o: $(SRCROOT)/%.c $(INCLUD)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	make clean -C ../utils
	make clean -C ../minilibx-linux
	$(RM) -r $(OBJROOT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette $(SRCROOT) $(INCDIRS)

test:

-include $(DEPS)

.PHONY: all clean fclean re norm atest test test1 test2 test3 test4 test5 test6 solo
