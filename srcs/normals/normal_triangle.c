/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:33:30 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/17 14:56:49 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3			triangle_normal(t_object *object, t_ray *ray)
{
	t_vect3		ca;
	t_vect3		ba;

	(void)ray;
	ca = vect_sub(object->point_c, object->point_a);
	ba = vect_sub(object->point_b, object->point_a);
	return (normalize(cross(ba, ca)));
}
