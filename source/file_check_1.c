/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:55:34 by fbafica           #+#    #+#             */
/*   Updated: 2022/04/10 21:27:48 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	file_check(char *file_name, t_parameters *parameters)
{
	char	**tokens;

	if (ft_strcmp(ft_strrchr(file_name, '.'), ".rt") != 0)
		return (send_error("Error\nBad extension"));
	if (load_file(file_name, &tokens) == -1)
		return (send_error("Error\nCould not open the file"));
	if (check_for_a(tokens, parameters) == -1)
		send_error("Error\nThere's no any Ambient Lightning parameter"))
	else if (check_for_c(tokens, parameters) == -1)
		send_error("Error\nThere's no any Camera parameter"))
	else if (check_for_l(tokens, parameters) == -1)
		send_error("Error\nThere's no any Light parameter"))
	else if (check_for_objects(tokens, parameters) == -1)
		send_error("Error\nThere's no any Object parameter"))
	free_tokens(tokens);
	return (0);
}
