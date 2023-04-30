#include "../includes/miniRT.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*  render dot on minilibx image. return true if can render  */
bool	render_dot(t_vector vec, t_data *img)
{
	int	mlx_x;
	int	mlx_y;

	mlx_x = vec.x + WIN_MID;
	mlx_y = vec.y + WIN_MID;
	if (mlx_x <= 0 || WIN_SIZE <= mlx_x)
		return (false);
	if (mlx_y <= 0 || WIN_SIZE <= mlx_y)
		return (false);
	my_mlx_pixel_put(img, mlx_x, mlx_y, vec.color);
	return (true);
}

/*  ratio : 1 - ratio  */
t_vector	get_internal_vector(t_vector start, t_vector end, double ratio)
{
	t_vector	target;
	double		s;
	double		t;
	int			color;

	s = 1 - ratio;
	t = ratio;
	target.x = s * start.x + t * end.x;
	target.y = s * start.y + t * end.y;
	target.z = s * start.z + t * end.z;
	color = (int)(s * (start.color & RED) + t * (end.color & RED)) & RED;
	color += (int)(s * (start.color & GREEN) + t * (end.color & GREEN)) & GREEN;
	color += (int)(s * (start.color & BLUE) + t * (end.color & BLUE)) & BLUE;
	target.color = color;
	return (target);
}

/*  render line between two vectors  */
void	render_line(t_data *img, t_vector start, t_vector end)
{
	double		ratio;
	double		diff;
	t_vector	target;

	if (!render_dot(start, img) && !render_dot(end, img))
		return ;
	diff = max_abs_3(end.x - start.x, end.y - start.y, end.z - start.z);
	ratio = 0;
	while (ratio <= 1)
	{
		target = get_internal_vector(start, end, ratio);
		render_dot(target, img);
		ratio += (double)DELTA_RATIO / diff;
	}
}



int main(void)
{
    t_miniRT    miniRT;
    t_vector    vec1;
    t_vector    vec2;

    vec1.x = 100;
    vec1.y = 100;
    vec1.z = 100;
    vec1.color = RED;
    vec2.x = 400;
    vec2.y = 400;
    vec2.z = 400;
    vec2.color = RED;

    miniRT.mlx = mlx_init();
    miniRT.win = mlx_new_window(miniRT.mlx, WIN_SIZE, WIN_SIZE, " miniRT ");
    miniRT.img.img = mlx_new_image(miniRT.mlx, WIN_SIZE, WIN_SIZE);
	miniRT.img.addr = mlx_get_data_addr(miniRT.img.img, &miniRT.img.bits_per_pixel, \
			&miniRT.img.line_length, &miniRT.img.endian);
    render_line(miniRT.img, vec1, vec2);
	mlx_put_image_to_window(miniRT.mlx, miniRT.win, miniRT.img.img, 0, 0);
    mlx_loop(miniRT.mlx);
    return (0);
}
