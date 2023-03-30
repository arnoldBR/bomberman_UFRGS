#include <stdio.h>
#include <string.h>
#include "raylib.h"
#include "raymath.h"
#include "tile_funcs.h"
#include "consts.h"
#include "game_structs.h"
#include "initialize.h"

int main(void)
{
    printf("\n\n Hey whatsup??? \n\n");

    int x, y; //iteradores para loops for.
    
    // tamanho do level em tiles:
    //int nLevelWidth = 64;
    //int nLevelHeight = 16;
    char sLevel[N_LEVEL_WDT * N_LEVEL_HGT + 1] = "\0";
    strcat(sLevel, ".#..............................................................");
    strcat(sLevel, "................................................................");
    strcat(sLevel, "......#####.....................................................");
    strcat(sLevel, "..........#####.................................................");
    strcat(sLevel, ".................................................#..............");
    strcat(sLevel, "............................................###.#.#.............");
    strcat(sLevel, "..........................................#####.#..#............");
    strcat(sLevel, ".................#.#..#................########.#...#...........");
    strcat(sLevel, "................................###############.#....#..........");
    strcat(sLevel, ".........######################################.#.....#.........");
    strcat(sLevel, "..............................................#.########........");
    strcat(sLevel, "..............................................#############.....");
    strcat(sLevel, "................................................................");
    strcat(sLevel, "................................................................");
    strcat(sLevel, "................................................................");
    strcat(sLevel, "................................................................");

    // Inicializacoes
    InitPlayer();
    InitializeCamera();
    

    //int nVisibleTilesX = N_LEVEL_WDT;
    //int nVisivleTilesY = N_LEVEL_HGT;

    //Calculate Top-Leftmost Visivle Tile
    //float fOffsetX = cam.target.x - (float)nVisibleTilesX / 2.0;
    //float fOffsetY = cam.target.y - (float)nVisivleTilesY /2.0;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "UFRGS - BOMBERMAN");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        player.vel = (Vector2){0,0};
        
        if(IsWindowFocused()){
            if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)){
                player.vel.y = -speed;
            }
            if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)){
                player.vel.y = +speed;
            }
            if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
                player.vel.x = -speed;
            }
            if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
                player.vel.x = +speed;
            }
        }

        player.pos = Vector2Add(player.pos, Vector2Scale(player.vel, GetFrameTime()));
        if (player.pos.x<0)
            player.pos.x *= 0;
        if (player.pos.y<0)
            player.pos.y *= 0;
        if (player.pos.x > TILE_WIDTH * N_LEVEL_WDT - TILE_WIDTH)
            player.pos.x = (TILE_WIDTH * N_LEVEL_WDT - TILE_WIDTH);
        if (player.pos.y > TILE_HEIGHT * N_LEVEL_HGT - TILE_HEIGHT)
            player.pos.y = TILE_HEIGHT * N_LEVEL_HGT - TILE_HEIGHT;
        


        cam.target = player.pos; 
 
        if(cam.target.x < cam.offset.x/ZOOM) 
            cam.target.x = cam.offset.x/ZOOM;
    
        if(cam.target.x > (TILE_WIDTH*N_LEVEL_WDT) - cam.offset.x/ZOOM) 
            cam.target.x = (TILE_WIDTH*N_LEVEL_WDT) - cam.offset.x/ZOOM;
        
        if(cam.target.y < cam.offset.y/ZOOM)
            cam.target.y = cam.offset.y/ZOOM;
        
        if(cam.target.y > (TILE_HEIGHT*N_LEVEL_HGT) - cam.offset.y/ZOOM)
            cam.target.y = (TILE_HEIGHT*N_LEVEL_HGT) - cam.offset.y/ZOOM;
        

        BeginDrawing();
        BeginMode2D(cam);

        for (x = 0; x < N_LEVEL_HGT; x++){
            for (y = 0; y < N_LEVEL_WDT; y++){
                char sTileID = GetTile(x, y, sLevel);
                //printf("%c\n", sTileID);
                switch (sTileID){
                    case '.':
                        DrawRectangle(x*TILE_WIDTH, y*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, SKYBLUE);
                        break;
                    case '#':
                        DrawRectangle(x*TILE_WIDTH, y*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, RED);
                        break;
                    default:
                        DrawRectangle(x*TILE_WIDTH, y*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, BLACK);
                        break;
                }
            }
        }

        DrawRectangle(player.pos.x, player.pos.y, TILE_WIDTH, TILE_HEIGHT, LIME); 
        DrawRectangle(0, 0, TILE_WIDTH, TILE_HEIGHT, YELLOW); 
        // para identificar a origem.


        EndMode2D();
        EndDrawing();
    }
    
    CloseWindow();        // Close window and OpenGL context

    return 0;
}