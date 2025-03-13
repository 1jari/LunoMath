#ifndef _WINDOW_HPP
#define _WINDOW_HPP

#include <string>
#include <vector>
#include <iostream>
#include <SDL2/SDL.h>
#include "../Module/Module.hpp"

namespace Versis {
  namespace Engine {
    namespace Runtime {
      class Window : public Module {
      public:
        // Constructor with default values for position
        
        Window::Window( const char* title, 
                        int         width,
                        int         height) : title(title), 
                                              w(width), 
                                              h(height), 
                                              isInitialized(false) {}
        ~Window() {
          if (window) {
            SDL_DestroyWindow(window);
          }
          if (isInitialized) {
            SDL_Quit();
          }
        } 

        bool Start() override;

        int   GetWidth()  const;
        int   GetHeight() const;
        const 
        char *GetTitle()  const;
        
        SDL_Window *GetHandle() const;

      private: 
        struct {
          int         w;
          int         h;
          const char* title; 
          SDL_Window* window;
        }; 
        bool  isInitialized; // Track SDL initialization
      };
    }
  }
}

#endif //_WINDOW_HPP
