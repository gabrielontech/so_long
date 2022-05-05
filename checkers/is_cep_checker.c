#include "../so_long.h"

int is_collector(char c)
{
    if(c != 'C')
        return(0);
    return(1);
}

int is_exit(char e)
{
    if(e != 'E')
        return(0);
    return(1);
}

int is_player(char p)
{
    if(p != 'P')
        return(0);
    return(1);
}

int is_wall(char *line)
{
    int i;

    i = 0;
    while(line[i] != '\0')
    {
        if(line[i] != '1')
        {
            return(0);
        }
        i++;
    }
    return(1);
}