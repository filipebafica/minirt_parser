/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:26:19 by fbafica           #+#    #+#             */
/*   Updated: 2022/04/11 15:41:20 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	main(int argc, char **argv)
{
	t_parameters	*p;
	
	if (argc != 2)
	{
		ft_putendl_fd("Error\nBad arguments", 1);
		return (1);
	}
	p = malloc(sizeof(t_parameters));
	if (file_check(argv[1], p) == -1)
		free(p);
	return (0);
}
