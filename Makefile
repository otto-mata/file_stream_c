NAME=libfstream.a
AR=ar rcs
CFLAGS=-Wall -Wextra -Werror -MMD -I./includes
CC=clang
SRC=stream.c \
	seek.c \
	read.c \
	write.c \
	open.c \
	setopt.c \
	readx.c \
	writex.c
SRC=$(addprefix "src/", $(SRC))
OBJDIR=./build
OBJ=$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
-include=$(OBJ:.o=.d)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^

all: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

default: $(NAME)

.PHONY: default re fclean clean all
