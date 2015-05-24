/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/14 10:39:30 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/23 16:09:48 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_object		new_cylinder(t_vertex pos, float radius, t_vector rot)
{
	t_object	object;
	t_matrix	s;
	t_matrix	r;
	t_matrix	t;

	s = get_scale_matrix(radius, radius, radius);
	r = get_rot_matrix(rot.x, rot.y, rot.z);
	t = get_trans_matrix(pos.x, pos.y, pos.z);
	object.o2w = matrix_product(t, matrix_product(r, s));
	s = get_scale_matrix(1 / radius, 1 / radius, 1 / radius);
	object.no2w = matrix_product(t, matrix_product(r, s));
	t = get_trans_matrix(-pos.x, -pos.y, -pos.z);
	r = get_rot_matrix(-rot.x, -rot.y, -rot.z);
	s = get_scale_matrix(1 / radius, 1 / radius, 1 / radius);
	object.w2o = matrix_product(s, matrix_product(r, t));
	object.intersect = intersect_cylinder;
	object.get_normal = cylinder_normal;
	return (object);
}
