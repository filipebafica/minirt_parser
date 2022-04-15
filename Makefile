# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 19:34:56 by fbafica           #+#    #+#              #
#    Updated: 2022/04/14 21:53:00 by fbafica          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
NAME_BONUS = program_bonus

SOURCE = main.c \
	file_check.c file_check_for_a.c file_check_for_c.c file_check_for_l.c \
	file_check_for_sp.c file_check_for_pl.c file_check_for_cy.c \
	file_check_utils_1.c file_check_utils_2.c \
	error_message.c load_file.c tokens_utils_1.c list_utils_1.c \

SOURCE_BONUS = main_bonus.c \
	file_check_bonus.c file_check_for_a_bonus.c file_check_for_c_bonus.c file_check_for_l_bonus.c \
	file_check_for_sp_bonus.c file_check_for_pl_bonus.c file_check_for_cy_bonus.c \
	file_check_utils_1_bonus.c file_check_utils_2_bonus.c \
	error_message_bonus.c load_file_bonus.c tokens_utils_1_bonus.c list_utils_1_bonus.c \

VPATH = ./source/mandatory/ ./source/bonus/

INCLUDES = ./includes/mandatory/
INCLUDES_BONUS = ./includes/bonus/

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

bonus: $(NAME_BONUS)

$(NAME): $(OBJECTS_DIR) $(OBJECTS) $(LIBFT)
	@$(CC) $(OBJECTS) $(LIBFT) $(FLAGS) -I $(LIBFT_INCLUDES) -I $(INCLUDES) -o $@

$(NAME_BONUS): $(OBJECTS_DIR_BONUS) $(OBJECTS_BONUS) $(LIBFT)
	@$(CC) $(OBJECTS_BONUS) $(LIBFT) $(FLAGS) -I $(LIBFT_INCLUDES) -I $(INCLUDES_BONUS) -o $@

$(OBJECTS_DIR)%.o: %.c
	@$(CC) $(FLAGS) -c $< -I $(LIBFT_INCLUDES) -I $(INCLUDES) -o $@

$(OBJECTS_DIR_BONUS)%.o: %.c
	@$(CC) $(FLAGS) -c $< -I $(LIBFT_INCLUDES) -I $(INCLUDES_BONUS) -o $@

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR_BONUS):
	@mkdir -p $(OBJECTS_DIR_BONUS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJECTS_DIR)
	@rm -rf $(OBJECTS_DIR_BONUS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
