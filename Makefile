NAME = miniRT_parser
SOURCE = main.c 

VPATH = ./source/utils/

INCLUDES = ./includes/
OBJECTS_DIR = ./objects/
OBJECTS = $(SOURCE:%.c=$(OBJECTS_DIR)%.o)

LIBFT = ./libs/libft/libft.a
LIBFT_INCLUDES = ./libs/libft/includes/
LIBFT_DIR = ./libs/libft/

FLAGS = -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS) $(LIBFT)
	@$(CC) $(OBJECTS) $(LIBFT) $(FLAGS) -I $(LIBFT_INCLUDES) -I $(INCLUDES) -o $@

$(OBJECTS_DIR)%.o: %.c
	@$(CC) $(FLAGS) -c $< -I$(INCLUDES) -I$(LIBFT_INCLUDES) -o $@

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJECTS_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm $(NAME)
