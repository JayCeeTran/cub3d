#ifndef CUB3D_H
#define CUB3D_H

#include <fcntl.h>
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_player{
	int x;
	int y;
} t_player;

typedef struct s_images{
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
} t_images; 

typedef struct s_map{
	size_t rows;
	size_t cols;
} t_map;

typedef struct s_data{
	void	*mlx;
	t_images *w_imgs;
	t_player *player;	

} t_data;

int	err_msg(char *s);

/**	
***	VALIDATION!
**/

t_data	*validate_args(int ac, char ** av);
void	validate_map(t_data *data, char *s);
void	validate_path(t_data *data, char *s);
int	ft_mod_strnstr(const char *str, const char *search, size_t n);


/**
***	MAP READING
**/

void	read_map(t_data *data, int fd);
void	process_line_and_save_info(t_data *data, char *s);
int	verify_element(t_data *data, char *s);

#endif
