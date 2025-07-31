# **************************************************************************** #
#                               MAKEFILE CONFIG                                #
# **************************************************************************** #

NAME        = pipex

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes -g

# Source folders
SRC_DIR     = src
PARSE_DIR   = $(SRC_DIR)/parser
SORT_DIR    = $(SRC_DIR)/sorting
UTILS_DIR   = $(SRC_DIR)/utils
OPS_DIR     = $(SRC_DIR)/operations

# Source files
SRC_FILES = \
	$(SRC_DIR)/main.c \
	$(PARSE_DIR)/parser.c \
	$(UTILS_DIR)/ft_split.c \

# Object files
OBJ_FILES   = $(SRC_FILES:.c=.o)

# **************************************************************************** #
#                                MAKE RULES                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re