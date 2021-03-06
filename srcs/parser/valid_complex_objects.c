/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_complex_objects.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:46:52 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/28 16:38:25 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void				valid_cmp_for_triangle(t_node *n, int type)
{
	if (type == POINT_A)
		n->cmp.point_a = true;
	else if (type == COLOR)
		n->cmp.color = true;
	else if (type == POINT_B)
		n->cmp.point_b = true;
	else if (type == ROTATION)
		n->cmp.rotation = true;
	else if (type == TRANSLATION)
		n->cmp.translation = true;
	else if (type == POINT_C)
		n->cmp.point_c = true;
}

void				valid_cmp_for_ellipsoid(t_node *n, int type)
{
	if (type == POSITION)
		n->cmp.position = true;
	else if (type == COLOR)
		n->cmp.color = true;
	else if (type == ORIENTATION)
		n->cmp.orientation = true;
	else if (type == ROTATION)
		n->cmp.rotation = true;
	else if (type == TRANSLATION)
		n->cmp.translation = true;
	else if (type == DISTANCE)
		n->cmp.dist = true;
	else if (type == RADIUS_1)
		n->cmp.radius1 = true;
	else if (type == RADIUS_2)
		n->cmp.radius2 = true;
}

void				valid_cmp_for_torus(t_node *n, int type)
{
	if (type == POSITION)
		n->cmp.position = true;
	else if (type == COLOR)
		n->cmp.color = true;
	else if (type == ORIENTATION)
		n->cmp.orientation = true;
	else if (type == ROTATION)
		n->cmp.rotation = true;
	else if (type == TRANSLATION)
		n->cmp.translation = true;
	else if (type == RADIUS_1)
		n->cmp.radius1 = true;
	else if (type == RADIUS_2)
		n->cmp.radius2 = true;
}

void				valid_cmp_for_disk(t_node *n, int type)
{
	if (type == POSITION)
		n->cmp.position = true;
	else if (type == COLOR)
		n->cmp.color = true;
	else if (type == RADIUS)
		n->cmp.radius = true;
	else if (type == ORIENTATION)
		n->cmp.orientation = true;
	else if (type == ROTATION)
		n->cmp.rotation = true;
	else if (type == TRANSLATION)
		n->cmp.translation = true;
}
