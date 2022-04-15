# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 19:34:56 by fbafica           #+#    #+#              #
#    Updated: 2022/04/15 00:28:57 by fbafica          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
BONUS = program_bonus

SOURCE = main.c \
	file_check.c file_check_for_a.c file_check_for_c.c file_check_for_l.c \
	file_check_for_sp.c file_check_for_pl.c file_check_for_cy.c \
	file_check_utils_1.c file_check_utils_2.c \
	error_message.c load_file.c tokens_utils_1.c list_utils_1.c

SOURCE_BONUS = main.c \
	file_check.c file_check_for_a.c file_check_for_c.c file_check_for_l_bonus.c \
	file_check_for_sp.c file_check_for_pl.c file_check_for_cy.c \
	file_check_utils_1_bonus.c file_check_utils_2_bonus.c \
	error_message.c load_file.c tokens_utils_1.c list_utils_1_bonus.c

VPATH = ./source/

INCLUDES = ./includes/
HEADERS = ./includes/headers.h
HEADERS_BONUS = ./includes/headers_bonus.h

OBJECTS_DIR = ./objects/mandatory/
OBJECTS_DIR_BONUS = ./objects/bonus/
OBJECTS = $(SOURCE:%.c=$(OBJECTS_DIR)%.o)
OBJECTS_BONUS = $(SOURCE_BONUS:%.c=$(OBJECTS_DIR_BONUS)%.o)

LIBFT = ./libs/libft/libft.a
LIBFT_INCLUDES = ./libs/libft/includes/
LIBFT_DIR = ./libs/libft/

FLAGS = -g -fsanitize=address -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJECTS_DIR) $(OBJECTS) $(LIBFT)
	@$(CC) $(OBJECTS) $(LIBFT) $(FLAGS) -I $(LIBFT_INCLUDES) -o $@

$(BONUS): $(OBJECTS_DIR_BONUS) $(OBJECTS_BONUS) $(LIBFT)
	@$(CC) $(OBJECTS_BONUS) $(LIBFT) $(FLAGS) -I $(LIBFT_INCLUDES) -o $@

$(OBJECTS_DIR)%.o: %.c $(HEADERS) $(HEADERS_BONUS)
	@$(CC) $(FLAGS) -c $< -I $(INCLUDES) -I $(LIBFT_INCLUDES) -o $@

$(OBJECTS_DIR_BONUS)%.o: %.c $(HEADERS) $(HEADERS_BONUS)
	@$(CC) $(FLAGS) -c $< -I $(INCLUDES) -I $(LIBFT_INCLUDES) -o $@

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR_BONUS):
	@mkdir -p $(OBJECTS_DIR_BONUS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf ./objects/
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
