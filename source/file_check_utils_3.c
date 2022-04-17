/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_utils_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbafica <fbafica@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:29:29 by fbafica           #+#    #+#             */
/*   Updated: 2022/04/17 22:08:41 by fbafica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static float	*create_vector_tuple(float x, float y, float z)
{
	float	*vector_tuple;

	vector_tuple = malloc(sizeof(float) * 4);
	vector_tuple[X] = x;
	vector_tuple[Y] = y;
	vector_tuple[Z] = z;
	vector_tuple[W] = 0.0;
	return (vector_tuple);
}

static float	get_magnitude(float *tuple)
{
	return (sqrtf(\
	powf(tuple[X], 2) \
	+ powf(tuple[Y], 2) \
	+ powf(tuple[Z], 2)) \
	);
}

int	check_normalized(char *x, char *y, char *z)
{
	float	*vector;
	double	mag;

	vector = create_vector_tuple(ft_atof(x), ft_atof(y), ft_atof(z));
	mag = get_magnitude(vector);
	free(vector);
	if (fabs(mag - 1.0000) > 0.00001)
		return (-1);
	return (0);
}
