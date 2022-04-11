/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:26:19 by fbafica           #+#    #+#             */
/*   Updated: 2022/04/10 19:44:54 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error\nBad arguments", 1);
		return (1);
	}
	file_check(argv[1]);
	return (0);
}
