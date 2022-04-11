/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:55:34 by fbafica           #+#    #+#             */
/*   Updated: 2022/04/10 22:33:23 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int	check_for_obj(char **tokens, t_parameters *p)
{
	return (0);
}

static int	check_for_l(char **tokens, t_parameters *p)
{
	return (0);
}

static int	check_for_c(char **tokens, t_parameters *p)
{
	return (0);
}

static int	check_for_a(char **tokens, t_parameters *p)
{
	// call function to count parameters frequecy
}

int	file_check(char *file_name)
{
	char	**tokens;

	if (ft_strcmp(ft_strrchr(file_name, '.'), ".rt") != 0)
		return (send_error("Error\nBad extension"));
	if (load_file(file_name, &tokens) == -1)
		return (send_error("Error\nCould not open the file"));
	if (check_for_tab(tokens, p) == -1)
		return (send_error("Error\n'\\t' is not a valid character"));
	if (check_for_a(tokens, p) == -1)
		return (send_error("Error\nThere's no Ambient Lightning parameter"));
	else if (check_for_c(tokens, p) == -1)
		return (send_error("Error\nThere's no Camera parameter"));
	else if (check_for_l(tokens, p) == -1)
		return (send_error("Error\nThere's no Light parameter"));
	else if (check_for_obj(tokens, p) == -1)
		return (send_error("Error\nThere's no Object parameter"));
	free_tokens(tokens);
	return (0);
}
