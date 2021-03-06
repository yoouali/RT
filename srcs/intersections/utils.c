/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:44:19 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/20 14:38:30 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	equa_solu(double a, double b, double delta)
{
	double	t1;
	double	t2;

	t1 = (-b - sqrtf(delta)) / (2 * a);
	t2 = (-b + sqrtf(delta)) / (2 * a);
	if ((t1 <= t2 && t1 >= 0.0) || (t1 >= 0.0 && t2 < 0.0))
		return (t1);
	if ((t2 <= t1 && t2 >= 0.0) || (t2 >= 0.0 && t1 < 0.0))
		return (t2);
	return (-1);
}
