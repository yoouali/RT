/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:48:55 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/17 16:10:46 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

// double			hit_triangle(t_object *triangle, t_ray *ray)
// {
// 	t_tri		tr;
// 	t_intersect	i;

// 	tr.ca = vect_sub(triangle->point_c, triangle->point_a);
// 	tr.ba = vect_sub(triangle->point_b, triangle->point_a);
// 	tr.orientation = normalize(cross(tr.ca, tr.ba));
// 	tr.distance = dot(tr.orientation, triangle->point_a);
// 	tr.x = vect_sub(ray->origin, triangle->point_a);
// 	tr.a = -1.0 * dot(tr.x, tr.orientation);
// 	tr.b = dot(ray->direction, tr.orientation);
// 	tr.dist2plane = tr.a / tr.b;
// 	tr.q = vect_add(ray->origin, v_c_prod(ray->direction, tr.dist2plane));
// 	tr.ca = vect_sub(triangle->point_c, triangle->point_a);
// 	tr.qa = vect_sub(tr.q, triangle->point_a);
// 	i.t = dot(cross(tr.ca, tr.qa), tr.orientation);
// 	tr.bc = vect_sub(triangle->point_b, triangle->point_c);
// 	tr.qc = vect_sub(tr.q, triangle->point_c);
// 	i.t1 = dot(cross(tr.bc, tr.qc), tr.orientation);
// 	tr.ab = vect_sub(triangle->point_a, triangle->point_b);
// 	tr.qb = vect_sub(tr.q, triangle->point_b);
// 	i.t2 = dot(cross(tr.ab, tr.qb), tr.orientation);
// 	if (i.t >= 0.0 && i.t1 >= 0.0 && i.t2 >= 0.0)
// 		return (slice_obj(*triangle, *ray, tr.dist2plane));
// 	return (-1);
// }

double			hit_triangle(t_object *triangle, t_ray *r)
{
	t_tri		tr;
	t_intersect	i;
	double		det;
	double		inv_det;

	tr.ba = vect_sub(triangle->point_b, triangle->point_a);
	tr.ca = vect_sub(triangle->point_c, triangle->point_a);
	tr.qb = cross(r->direction, tr.ca);
	det = dot(tr.ba, tr.qb);
	if (det < 0.00001)
		return (-1);
	tr.q = vect_sub(r->origin, triangle->point_a);
	i.t1 = dot(tr.q, tr.qb);
	if (i.t1 < 0.0 || i.t1 > det)
		return (-1);
	tr.qa = cross(tr.q, tr.ba);
	i.t2 = dot(r->direction, tr.qa);
	if (i.t2 < 0.0 || i.t1 + i.t2 > det)
		return (-1);
	i.t = dot(tr.ca, tr.qa);
	inv_det = 1.0 / det;
	i.t1 *= inv_det;
	i.t2 *= inv_det;
	i.t *= inv_det;
	return (slice_obj(*triangle, *r, i.t));
}
