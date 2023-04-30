#include "../includes/miniRT.h"

int main(void)
{
    void *mlx;

    mlx = mlx_init();
    void    *win;
    win = mlx_new_window(mlx, 200, 200, " miniRT ");
    (void)mlx;
    (void)win;
    return (0);
}
