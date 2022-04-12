# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 19:34:56 by fbafica           #+#    #+#              #
#    Updated: 2022/04/11 23:26:04 by fbafica          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
SOURCE = main.c error_message.c load_file.c file_check.c file_check_for_a.c \
	file_check_utils_1.c file_check_utils_2.c tokens_utils_1.c \

VPATH = ./source/

INCLUDES = ./includes/
OBJECTS_DIR = ./objects/
OBJECTS = $(SOURCE:%.c=$(OBJECTS_DIR)%.o)

LIBFT = ./libs/libft/libft.a
LIBFT_INCLUDES = ./libs/libft/includes/
LIBFT_DIR = ./libs/libft/

FLAGS = -g -Wall -Werror -Wextra
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
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
