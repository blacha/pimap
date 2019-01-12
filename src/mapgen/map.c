int MAP_SIZE = 1500;
int MAP_ARRY_SIZE = 1500 * 1500;
int MAP[1500 * 1500];

#define MAP_DATA_INVALID -1      // Invalid
#define MAP_DATA_CLEANED 11110   // Cleaned for start/end positions
#define MAP_DATA_FILLED 11111    // Filled gaps
#define MAP_DATA_THICKENED 11113 // Wall thickened
#define MAP_DATA_AVOID 11115     // Should be avoided

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
        MAP[x] = MAP_DATA_INVALID;
    }
}
