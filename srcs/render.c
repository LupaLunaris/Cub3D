/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpaulis <Jpaulis@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:00:47 by Jpaulis           #+#    #+#             */
/*   Updated: 2025/08/10 17:21:10 by Jpaulis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_floor_and_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				put_pixel(game, x, y, game->textures.ceiling_color);
			else
				put_pixel(game, x, y, game->textures.floor_color);
			x++;
		}
		y++;
	}
}

void	render_scene(t_game *game)
{
	draw_floor_and_ceiling(game);
	cast_rays(game);
}

static void	draw_wall_stripe(t_game *game, t_ray *ray,
	t_texture *texture, t_draw_context ctx)
{
	int		y;
	int		texture_y;
	double	texture_pos;
	int		color;

	(void)ray;
	y = ctx.draw_start;
	texture_pos = (ctx.draw_start - SCREEN_HEIGHT / 2
			+ ctx.line_height / 2) * ctx.step;
	while (y < ctx.draw_end)
	{
		texture_y = (int)texture_pos & (texture->height - 1);
		texture_pos += ctx.step;
		color = get_texture_pixel(texture, ctx.texture_x, texture_y);
		put_pixel(game, ctx.x, y, color);
		y++;
	}
}

void	draw_wall_column(t_game *game, t_ray *ray, int x)
{
	t_texture		*texture;
	t_draw_context	ctx;

	texture = select_wall_texture(game, ray);
	ctx.line_height = (int)(SCREEN_HEIGHT / ray->perpendicular_wall_distance);
	ctx.draw_start = -ctx.line_height / 2 + SCREEN_HEIGHT / 2;
	if (ctx.draw_start < 0)
		ctx.draw_start = 0;
	ctx.draw_end = ctx.line_height / 2 + SCREEN_HEIGHT / 2;
	if (ctx.draw_end >= SCREEN_HEIGHT)
		ctx.draw_end = SCREEN_HEIGHT - 1;
	ctx.texture_x = get_texture_x(game, ray, texture);
	ctx.step = 1.0 * texture->height / ctx.line_height;
	ctx.x = x;
	draw_wall_stripe(game, ray, texture, ctx);
}
