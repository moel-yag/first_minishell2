CC = gcc

CFLAGS = -Wall -Wextra -Werror # -Iincludes -I./src/utils -I./src/shell -I./src/commands -I./src/parser -I./src/syntax

SRC = src/main.c  src/cmd.c  \
  src/libft_functs1.c src/utils.c \
  src/syntax/validate_syntax.c \
  src/syntax/pipe_syntax.c src/syntax/files_syntax.c src/syntax/syntax.c \

OBJ = $(SRC:.c=.o)

NAME = minishell

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lreadline -o $(NAME)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
