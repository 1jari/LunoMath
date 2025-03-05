#pragma once
#ifndef _APP_HPP
#define _APP_HPP

#include "../RuntimeCommon.hpp"

namespace Runtime {
  class App {
  public:
    App::App(): window(nullptr),
                renderer(nullptr),
                state(false) {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
          printf("SDL Initialization failed!\n");
        state = false;
      } else {
        state = true;
      }
    }
  
    void init(const char *title,
              int         width,
              int         height,
              bool        fullscreen);

    // Handle SDL events
    void handle();

    // To override...
    virtual void step() {};
    virtual void draw() {};

    void beginRender();
    void endRender();

    void clean();

    bool getState() const;
    
    ~App();
  private:
    bool          state;
    SDL_Window   *window;
    SDL_Renderer *renderer;
  };
};
#endif //_APP_HPP
