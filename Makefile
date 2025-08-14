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
UTILS_DIR   = $(SRC_DIR)/utils

# Source files
SRC_FILES = \
	$(SRC_DIR)/main.c \
	$(UTILS_DIR)/ft_split.c \
	$(UTILS_DIR)/ft_strjoin.c \
	$(UTILS_DIR)/ft_parse_error.c \
	$(UTILS_DIR)/ft_putstr_fd.c \
	$(UTILS_DIR)/ft_strncmp.c \
	$(UTILS_DIR)/ft_calloc.c \
	$(UTILS_DIR)/ft_strlen.c \
	$(UTILS_DIR)/ft_sys_error.c \
	$(UTILS_DIR)/ft_bzero.c \
	$(PARSE_DIR)/parser.c \
	$(PARSE_DIR)/is_command_valid.c \
	$(PARSE_DIR)/is_file1_valid.c \
	$(PARSE_DIR)/is_file2_valid.c \

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