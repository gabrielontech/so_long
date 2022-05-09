void    displayer(t_data *data, t_map *map)
{
    int i;
    int j;
    t_vector vector;

    i = 0;
    j = 0;
    vector.v_x = 0;
    vector.v_y = 0;
    while(map[i] != NULL)
    {
        j = 0;
        while(map[i][j] != '\0'){
            vector->v_x += 48
            if(map[i][j] == '1')
                display_wall(&data, &vector);
            if(map[i][j] == 'C')
                display_collect(&data, &vector);
            if(map[i][j] == 'P')
                display_player(&data, &vector);
            if(map[i][j] == 'E')
                display_close(&data, &vector);
            if(map[i][j] == '0')
                display_floor(&data, &vector);
            j++;
        }
        vector->v_y =+ 48
        vector-> v_x = 0;
        i++;
    }
}