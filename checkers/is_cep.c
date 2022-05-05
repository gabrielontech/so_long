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
    if(p != 'E')
        return(0);
    return(1);
}
