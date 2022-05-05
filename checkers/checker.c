#include "../so_long.h"

void checker(int ac, char **ag)
{
    if(ac != 2)
        ft_error();
    if(ft_strncmp(ft_strchr(ag[1], '.'), ".ber", 4) != 0)
    {
        ft_putstr_fd("Error : Wrong type file, file name must : <filename>.ber\n", 2);
        exit(EXIT_FAILURE);
    }
}

void check_map_content(t_map map)
{
    int i;
    int j;

    i = 0;
    while(map.v_map[i] != NULL)
    {
        j = 0;
        while(map.v_map[i][j] != '\0')
        {
            if(map.v_map[i][j] != '0' && map.v_map[i][j] && '1' && map.v_map[i][j] && 'C' && map.v_map[i][j] != 'E' && map.v_map[i][j] != 'P')
            {
                ft_putstr_fd("Error : Wrong map content  \n", 2);
                exit(EXIT_FAILURE);
            }
            j++;
        }
        i++;
    }
}

void check_if_map_is_rect(t_map map)
{
    int i;
    int j;

    i = 0;
    while(map.v_map[i] != NULL)
        i++;
    map.v_height = i;
    i = 0;
    j = 1;
    while(map.v_map[i] != NULL)
    {
        if(ft_strlen(map.v_map[i]) == ft_strlen(map.v_map[j]))
        {
            if(map.v_map[i + 2] != NULL)
            {
                j++;
            }
        } else 
        {
            ft_putstr_fd("Error : Please make sure that you map follows the rectangle rules !\n", 2);
            exit(EXIT_FAILURE);
        } 
        i++;
    }
    map.v_width = ft_strlen(map.v_map[0]);
}
