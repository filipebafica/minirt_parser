/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_for_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:14:55 by fbafica           #+#    #+#             */
/*   Updated: 2022/04/11 23:50:38 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static void	update_a_parameters(char **a_tokens, t_parameters *p)
{
	(void)p;
	(void)a_tokens;
}

static int validate_a_tokens(char **a_tokens)
{
	if (ft_strcmp(*a_tokens, "A"))
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

