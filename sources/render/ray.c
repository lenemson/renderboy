/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:26:34 by jibanez           #+#    #+#             */
/*   Updated: 2015/05/29 13:36:57 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_ray			new_ray(t_vertex o, t_vector dir)
{
	t_ray		ray;

	ray.o = o;
	ray.dir = normalize(dir);
	ray.t = 0;
	return (ray);
}

t_ray			construct_ray(t_camera const camera,
								t_vector const up,
								int const x)
{
	t_ray		ray;
	t_vertex	viewplane;
	t_vector	right;

	right = mult_vector(camera.right, (float)x * camera.x_indent);
	viewplane = vector_sum(camera.viewplane, right);
	viewplane = vector_diff(viewplane, up);
	ray.dir = vector_diff(viewplane, camera.pos);
	ray.dir = normalize(ray.dir);
	ray.o = camera.pos;
	ray.t = 0;
	return (ray);
}

t_ray			mult_matrix_ray(t_ray const src, t_matrix const m)
{
	t_ray	dst;

	dst.t = src.t;
	dst.o = mult_matrix_vertex(src.o, m);
	dst.dir = mult_matrix_vector(src.dir, m);
	return (dst);
}
