/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:55:34 by fbafica           #+#    #+#             */
/*   Updated: 2022/04/11 20:12:45 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	file_check(char *file_name, t_parameters *p)
{
	char	**file_tokens;

	if (ft_strcmp(ft_strrchr(file_name, '.'), ".rt") != 0)
		return (send_error("Error\nBad extension"));
	if (load_file(file_name, &file_tokens) == -1)
		return (send_error("Error\nCould not open the file"));
	if (check_for_tab(file_tokens) == -1)
		return (send_error("Error\n'\\t' is not a valid character"));
	else if (check_for_a(file_tokens, p) == -1)
		return (send_error("Error\nBad Ambient Lightning parameter"));
	// else if (check_for_c(tokens, p) == -1)
	// 	return (send_error("Error\Bad Camera parameter"));
	// else if (check_for_l(tokens, p) == -1)
	// 	return (send_error("Error\Bad Light parameter"));
	// else if (check_for_obj(tokens, p) == -1)
	// 	return (send_error("Error\Bad Object parameter"));
	(void)p;
	free_tokens(file_tokens);
	return (0);
}