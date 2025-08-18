# **************************************************************************** #
#                               MAKEFILE CONFIG                                #
# **************************************************************************** #

NAME        = pipex

# Compiler and flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iincludes -g

# Source folders
SRC_DIR     = src
HELPE_DIR	= $(SRC_DIR)/helpers
PARSE_DIR   = $(SRC_DIR)/parser
PIPE__DIR	= $(SRC_DIR)/pipe
UTILS_DIR   = $(SRC_DIR)/utils
MAIN__DIR	= $(SRC_DIR)

# Source files
SRC_FILES = \
	$(HELPE_DIR)/ft_bzero.c \
	$(HELPE_DIR)/ft_calloc.c \
	$(HELPE_DIR)/ft_putstr_fd.c \
	$(HELPE_DIR)/ft_split.c \
	$(HELPE_DIR)/ft_strjoin.c \
	$(HELPE_DIR)/ft_strlen.c \
	$(HELPE_DIR)/ft_strncmp.c \
	$(PARSE_DIR)/get_all_paths.c \
	$(PARSE_DIR)/get_cmd_path.c \
	$(PARSE_DIR)/get_cmd.c \
	$(PARSE_DIR)/is_cmd_valid.c \
	$(PARSE_DIR)/is_file1_valid.c \
	$(PARSE_DIR)/is_file2_valid.c \
	$(PARSE_DIR)/parser.c \
	$(UTILS_DIR)/ft_error.c \
	$(UTILS_DIR)/ft_free_struct.c \
	$(UTILS_DIR)/init_struct.c \
	$(MAIN__DIR)/main.c \

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