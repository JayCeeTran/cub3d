#include "cub3d.h"
#include "libft/libft.h"

int	err_msg(char *s)
{
	write(2, s, ft_strlen(s));
	return(1);
}
