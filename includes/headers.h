/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:01:39 by fbafica           #+#    #+#             */
/*   Updated: 2022/04/12 14:42:15 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_object
{
	char				*identifier;
	float				*cordinates;
	float				*color;
	float				*orientation_vector;
	float				diameter;
	float				height;
	struct s_object		*next;
}	t_object;

typedef struct s_parameters
{
	float			a_lighting;
	float			*a_color;
	float			*c_view_point;
	float			*c_orientation_vector;
	float			*c_fov;
	float			*l_light_point;
	float			*l_britghness;
	float			*l_color;
	t_object		*object_head;
}	t_parameters;

				/*
				* FILE PARSER 
				*/
int			file_check(char *file_name, t_parameters *p);
int			load_file(char *file_name, char ***tokens);
int			send_error(char *error_message);
int			check_for_tab(char **tokens);
int			check_for_a(char **tokens, t_parameters *p);
int			check_for_c(char **tokens, t_parameters *p);
int			check_for_l(char **tokens, t_parameters *p);
int			check_for_obj(char **tokens, t_parameters *p);
void		free_tokens(char **tokens);
void		print_tokens(char **tokens);
int			get_tokens_len(char **tokens);
int			count_identifiers(char **tokens, char *identifier);
int			get_line(char **tokens, char *identidier);
void		space_handler(char **input);
char		**tokenize_line(char *line);
int			check_if_digit(char *token);

#endif