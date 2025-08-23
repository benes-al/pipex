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
PROGR_DIR   = $(SRC_DIR)/program
PIPE__DIR	= $(SRC_DIR)/pipe
UTILS_DIR   = $(SRC_DIR)/utils
MAIN__DIR	= $(SRC_DIR)

# Source files
SRC_FILES = \
	$(HELPE_DIR)/ft_bzero.c \
	$(HELPE_DIR)/ft_calloc.c \
	$(HELPE_DIR)/ft_isallspaces.c \
	$(HELPE_DIR)/ft_putstr_fd.c \
	$(HELPE_DIR)/ft_split.c \
	$(HELPE_DIR)/ft_strjoin.c \
	$(HELPE_DIR)/ft_strlen.c \
	$(HELPE_DIR)/ft_strncmp.c \
	$(PROGR_DIR)/child1_process.c \
	$(PROGR_DIR)/child2_process.c \
	$(PROGR_DIR)/ft_wait.c \
	$(PROGR_DIR)/get_all_paths.c \
	$(PROGR_DIR)/get_cmd_path.c \
	$(PROGR_DIR)/get_cmd.c \
	$(PROGR_DIR)/parse_and_open_file1.c \
	$(PROGR_DIR)/parse_and_open_file2.c \
	$(PROGR_DIR)/parse_and_store_cmd1.c \
	$(PROGR_DIR)/parse_and_store_cmd2.c \
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

valgrind: $(NAME)
	@echo "$(YELLOW)Valgrind Report$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
	--track-origins=yes --trace-children=yes \
	./$(NAME) infile wc "cat -e" outfile

.PHONY: all clean fclean re