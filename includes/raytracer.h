/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 16:32:15 by jibanez           #+#    #+#             */
/*   Updated: 2015/02/26 11:19:54 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "render.h"

struct					s_scene
{
	t_env				gfx;
	t_camera			camera;
};

typedef struct s_scene	t_scene;

int				raytracer(t_scene scene, int res_x, int res_y);

#endif
