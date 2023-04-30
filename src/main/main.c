#include "../includes/miniRT.h"

int main(void)
{
    t_miniRT    miniRT;
    void *mlx;

    miniRT.mlx = mlx_init();
    void    *win;
    miniRT.win = mlx_new_window(miniRT.mlx, 200, 200, " miniRT ");
    miniRT.img.img = mlx_new_image(miniRT.mlx, WIN_SIZE, WIN_SIZE);
	miniRT.img.addr = mlx_get_data_addr(miniRT.img.img, &miniRT.img.bits_per_pixel, \
			&miniRT.img.line_length, &miniRT.img.endian);
	mlx_put_image_to_window(miniRT.mlx, miniRT.win, miniRT.img.img, 0, 0);
    return (0);
}
