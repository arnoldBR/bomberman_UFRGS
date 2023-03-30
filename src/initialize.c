#include "consts.h"
#include "initialize.h"


// Inicializa a posicao do player e sua velocidade.
Player InitPlayer()
{
    Player player;

    player.pos = (Vector2){(N_LEVEL_WDT * TILE_WIDTH)/2, (N_LEVEL_HGT * TILE_HEIGHT)/2};
    player.speed = 120;
    return player;
}

// Inicializa os parametros da camera.
Camera2D InitializeCamera()
{
    Camera2D cam = {0};
    cam.zoom = ZOOM;
    cam.target = (Vector2){0,0};//{LEVEL_WIDTH/2.0, LEVEL_HEIGHT/2.0}; // a posicao da camera depois mudara para seguir o player.
    cam.offset = (Vector2){WINDOW_WIDTH/2.0, WINDOW_HEIGHT/2.0};
    return cam;
}
