/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 15:08:43 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/25 11:13:10 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "camera.h"
#define PI 3.14159265

/*
** Set the FOV by computing view distance
*/

t_camera	set_fov(t_camera camera, float fov)
{
	float	tan_a;
	float	oposite_side;
	float	adjacent_side;

	tan_a = tan(((fov / 2) * PI) / 180.0);
	oposite_side = camera.viewplane_width / 2.0;
	adjacent_side = 1 / (tan_a / oposite_side);
	camera.view_distance = adjacent_side;
	camera = set_viewplane_pos(camera);
	return (camera);
}
