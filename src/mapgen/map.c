#define MAP_SIZE 1500;
#define MAP_ARRY_SIZE 1500 * 1500
int MAP[MAP_ARRY_SIZE];

int map_offset(int x, int y)
{
    return x * MAP_SIZE + y;
}

int map_value(int x, int y)
{
    return MAP[map_offset(x, y)];
}

void map_set(int x, int y, int value)
{
    MAP[map_offset(x, y)] = value;
}

void map_reset()
{
    for (int x = 0; x < MAP_ARRY_SIZE; x++)
    {
        MAP[x] = 0;
    }
}
