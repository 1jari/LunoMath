#include "./App.hpp"

namespace Runtime {

  void App::init(const char *title,
                 int         width,
                 int         height,
                 bool        fullscreen) {

    // Setting up Window Flags
    int flags = 0;
    
    if(fullscreen) {
      flags = SDL_WINDOW_FULLSCREEN;
    }

    // Window creation routines...
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
      printf("Initilizing Subsystems...\n");

      window = SDL_CreateWindow(title, 200, 200,
                                width, height, flags);

      if(window) {
        printf("Window Created!\n");
      }

      renderer = SDL_CreateRenderer(window, -1, 0);

      if(renderer) {
        printf("Renderer Created !\n");
      }

      // Set the state as true...
      state = true;
    } else {
      state = false;
    }
  }

  void App::handle() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
    case SDL_QUIT:
      state = false;
      break;
    default:
      break;
    }
  }


  void App::beginRender() {
    SDL_SetRenderDrawColor(renderer, 12, 128, 116, 255);
  }

  void App::endRender() {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }
  
  void App::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    printf("Done!\n");
  }

  bool App::getState() const {
    return state;
  }
  
  App::~App() {}
};
