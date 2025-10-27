#include "cub3d.h"

t_data	*validate_args(int ac, char **av)
{
	if(ac != 2)
		exit(err_msg("Error: Input ./cub3D path_to_map.cub\n"));
	t_data *data;
	data = malloc(sizeof(t_data));
	if(!data)
		exit(err_msg("Error: Malloc Failed!\n"));
	validate_map(data, av[1]);
	return(NULL);
}

void	validate_map(t_data *data, char *s)
{
	validate_path(data, s);
}

void	validate_path(t_data *data, char *s)
{
	int fd;

	if(!ft_mod_strnstr(s, ".cub", ft_strlen(s)))
		exit(err_msg("Error: Not a valid file. Needs .cub file\n"));
	fd = open(s, O_RDONLY);
	if(fd < 0)
		exit(err_msg("Error: Could not open file\n"));
	read_map(data, fd);
}

void	read_map(t_data *data, int fd)
{
	char *buffer;

	buffer = "";
	int i = 0;
	while((buffer = get_next_line(fd)))
	{
		printf("i am here\n");
		i++;
		if(i == 8)
			break;
		process_line_and_save_info(data, buffer);
	}
}

void	process_line_and_save_info(t_data *data, char *s)
{
	int i;
	
	i = 0;
	while(s[i] && s[i] == ' ')
		i++;
	if(s[i] == '\n' || s[i] == '\0')
		return ;
	verify_element(data, &s[i]);
	
	
}

int verify_element(t_data *data, char *s)
{
	char element[10];	

	int i;

	i = 0;
	while(s[i] && s[i] != ' ' && i < 4)
	{
		element[i] = s[i];
		element[i + 1] = '\0';
		i++;	
	}
	if(i > 2 || s[i] == '\0' || s[i] == '\n')
		exit(err_msg("Error: Invalid elements in map.\n"));
	while(s[i] && s[i] == ' ')
		i++;
	save_element(data, element, &s[i]);
	return(0);
}

void	save_element(t_data *data, char *element, char *s)
{
	if(ft_strcmp(element, "SO") == 0)
		//function
	else if(ft_strcmp(element, "NO") == 0)
		//function
	else if(ft_strcmp(element, "EA") == 0)
		//function
	else if(ft_strcmp(element, "WE") == 0)
		//function
	else if(ft_strcmp(element, "C") == 0)
		//function
	else if(ft_strcmp(element, "F") == 0)
		//function
	else
		exit(err_msg("Error: Not a valid element in map\n"));
}

void	load_image(t_data *data, char *path)
{

}
