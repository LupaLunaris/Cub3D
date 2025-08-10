/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cleanup2.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: Jpaulis <Jpaulis@student.s19.be>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/07/31 15:37:42 by Jpaulis		   #+#	#+#			 */
/*   Updated: 2025/08/06 XX:XX:XX by Jpaulis		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "../includes/cub3d.h"

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	cleanup_gnl_remainder();
	free_textures(game);
	free_texture_paths(game);
	free_mlx_resources(game);
	if (game->map.grid)
		free_map_grid(game->map.grid, game->map.height);
}

void	free_parsing_data(t_parsing *parsing)
{
	if (!parsing)
		return ;
	if (parsing->north_texture)
		free(parsing->north_texture);
	if (parsing->south_texture)
		free(parsing->south_texture);
	if (parsing->west_texture)
		free(parsing->west_texture);
	if (parsing->east_texture)
		free(parsing->east_texture);
	if (parsing->map_lines)
		free_map_grid(parsing->map_lines, parsing->map_height);
}

void	free_map_grid(char **grid, int height)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (i < height)
	{
		if (grid[i])
			free(grid[i]);
		i++;
	}
	free(grid);
}
