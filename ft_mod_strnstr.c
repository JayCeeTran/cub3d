#include "cub3d.h"

int    ft_mod_strnstr(const char *str, const char *search, size_t n)
{
        size_t  i;
        size_t  j;

        i = 0;
        if (!search[i])
                return (0);
        if ((!str || !search) && n == 0)
                return (0);
        while (str[i] && i < n)
        {
                j = 0;
                while (search[j] && (i + j) < n)
                {
                        if (str[i + j] == search[j])
                                j++;
                        else
                                break ;
                }
                if (search[j] == '\0' && str[i + j] == '\0')
                        return (1);
                i++;
        }
        return (0);
}
