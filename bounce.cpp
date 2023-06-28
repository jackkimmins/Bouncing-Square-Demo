#include <SDL.h>
#include <emscripten.h>
#include <cstdlib>
#include <ctime>

#define WIDTH 800
#define HEIGHT 600
#define BOX_SIZE 40
#define SPEED 2
#define MAX_COLOR_VALUE 256

static SDL_Window* window = nullptr;
static SDL_Renderer* renderer = nullptr;
static int directionX;
static int directionY;
static SDL_Rect square = { .x = WIDTH / 2, .y = HEIGHT / 2, .w = BOX_SIZE, .h = BOX_SIZE };
static int colors[3] = {255, 255, 255};

void ChangeColour()
{
    for (int i = 0; i < 3; i++) colors[i] = rand() % MAX_COLOR_VALUE;
}

void Render()
{
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw square
    SDL_SetRenderDrawColor(renderer, colors[0], colors[1], colors[2], 255);
    SDL_RenderFillRect(renderer, &square);

    // Update screen
    SDL_RenderPresent(renderer);
}

void Update()
{
    // Update square position.
    square.x += directionX;
    square.y += directionY;

    // Check for collision with window borders and change colour.
    if (square.x + square.w > WIDTH || square.x < 0)
    {
        directionX = -directionX;
        ChangeColour();
    }

    if (square.y + square.h > HEIGHT || square.y < 0)
    {
        directionY = -directionY;
        ChangeColour();
    }
}

void mainloop() {
    Update();
    Render();
}

int main()
{
    // Seed the random number generator.
    srand((unsigned int)time(NULL));

    // Random initial directions.
    directionX = (rand() % 2 ? 1 : -1) * SPEED;
    directionY = (rand() % 2 ? 1 : -1) * SPEED;

    // Initialise SDL
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Bouncing Square Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);

    emscripten_set_main_loop(mainloop, 0, 1);

    return 0;
}