#include "cub3d.h"


int main(void)
{
    void    *mlx;
    void    *win;
    void    *img;
    int     img_width;
    int     img_height;

    // Initialize MiniLibX
    mlx = mlx_init();
    if (!mlx)
        return (1);

    // Create a small window
    win = mlx_new_window(mlx, 800, 600, "XPM Test");
    if (!win)
        return (1);

    // Load your XPM image (change "image.xpm" to your filename)
    img = mlx_xpm_file_to_image(mlx, "wall.xpm", &img_width, &img_height);
    if (!img)
    {
        write(2, "Failed to load XPM image\n", 25);
        return (1);
    }

    // Display image at (0, 0)
    mlx_put_image_to_window(mlx, win, img, 0, 0);

    // Keep window open
    mlx_loop(mlx);
    return (0);
}

