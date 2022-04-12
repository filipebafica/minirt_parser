/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_for_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:14:55 by fbafica           #+#    #+#             */
/*   Updated: 2022/04/12 15:13:42 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static void	update_a_parameters(char **a_tokens, t_parameters *p)
{
	p->a_lighting = ft_atof(a_tokens[1]);
	p->a_color = malloc(sizeof(float) * 3);
	p->a_color[0] = ft_atoi(a_tokens[2]);
	p->a_color[1] = ft_atoi(a_tokens[4]);
	p->a_color[2] = ft_atoi(a_tokens[6]);
}

static int validate_a_tokens(char **a_tokens)
{
	if (get_tokens_len(a_tokens) != 7)
		return (-1);
	if (ft_strcmp(a_tokens[0], "A"))
		return (-1);
	if (check_if_digit(a_tokens[1]) < 0 || \
	ft_atof(a_tokens[1]) < 0 || ft_atof(a_tokens[1]) > 1)
		return (-1);
	if (ft_strcmp(a_tokens[3], ",") || ft_strcmp(a_tokens[5], ","))
		return (-1);
	if (check_if_digit(a_tokens[2]) < 0 || \
	ft_atoi(a_tokens[2]) < 0 || ft_atoi(a_tokens[2]) > 255)
		return (-1);
	if (check_if_digit(a_tokens[4]) < 0 || \
	ft_atoi(a_tokens[4]) < 0 || ft_atoi(a_tokens[4]) > 255)
		return (-1);
	if (check_if_digit(a_tokens[6]) < 0 || \
	ft_atoi(a_tokens[6]) < 0 || ft_atoi(a_tokens[6]) > 255)
		return (-1);
	return (0);
}

int	check_for_a(char **tokens, t_parameters *p)
{
	char	**a_tokens;
	char	status;

	status = 0;
	if (count_identifiers(tokens, "A") != 1)
		return (-1);
	a_tokens = tokenize_line(tokens[get_line(tokens, "A")]);
	if (validate_a_tokens(a_tokens) == -1)
		status = -1;
	else
		update_a_parameters(a_tokens, p);
	(void)p;
	free_tokens(a_tokens);
	return (status);
}

