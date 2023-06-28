#include <SDL.h>
#include <emscripten.h>
#include <cstdlib>
#include <ctime>

#define WIDTH 800
#define HEIGHT 600
#define BOX_SIZE 40
#define SPEED 2

static SDL_Window* window = nullptr;
static SDL_Renderer* renderer = nullptr;
static int directionX;
static int directionY;
static SDL_Rect square = { .x = WIDTH / 2, .y = HEIGHT / 2, .w = BOX_SIZE, .h = BOX_SIZE };
static int r = 255, g = 255, b = 255; // initial color is white

void render() {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw square
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillRect(renderer, &square);

    // Update screen
    SDL_RenderPresent(renderer);
}

void update() {
    // Update square position
    square.x += directionX;
    square.y += directionY;

    // Check for collision with window borders
    if (square.x + square.w > WIDTH || square.x < 0) {
        directionX = -directionX;
        r = rand() % 256;
        g = rand() % 256;
        b = rand() % 256;
    }
    if (square.y + square.h > HEIGHT || square.y < 0) {
        directionY = -directionY;
        r = rand() % 256;
        g = rand() % 256;
        b = rand() % 256;
    }
}

void mainloop() {
    update();
    render();
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Random initial directions
    directionX = (rand() % 2 ? 1 : -1) * SPEED;
    directionY = (rand() % 2 ? 1 : -1) * SPEED;

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Bouncing Square Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, 0);

    emscripten_set_main_loop(mainloop, 0, 1);

    return 0;
}