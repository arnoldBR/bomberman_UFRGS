
#define TILE_WIDTH      16 // height of tile in px
#define TILE_HEIGHT     16 // width of tile in px
#define N_LEVEL_HGT     16
#define N_LEVEL_WDT     64
#define LEVEL_HEIGHT    N_LEVEL_HGT * TILE_HEIGHT
#define LEVEL_WIDTH     N_LEVEL_WDT * TILE_WIDTH
#define ZOOM            3.5 //camera zoom factor
#define SCREEN_RATIO    4/3 

#define N_TILES_WINDOW_HEIGHT 16 // number of tiles appearing along window height
#define WINDOW_HEIGHT    ZOOM * N_TILES_WINDOW_HEIGHT * TILE_HEIGHT
#define WINDOW_WIDTH    WINDOW_HEIGHT * SCREEN_RATIO
