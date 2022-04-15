/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:16:36 by fbafica           #+#    #+#             */
/*   Updated: 2022/04/14 21:07:07 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers_bonus.h"

int	send_error(char *error_message)
{
	ft_putendl_fd(error_message, 2);
	return (-1);
}
