#include "./Window.hpp"
#include <iostream>

namespace Versis {
  namespace Engine {
    namespace Runtime {
      // Getters
      SDL_Window* Window::GetHandle() const {
        return window;
      }

      int Window::GetWidth() const {
        return w;
      }

      int Window::GetHeight() const {
        return h;
      }

      const char* Window::GetTitle() const {
        return title;
      }

      // Start method to initialize SDL and create the window
      bool Window::Start() {
        // Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
          std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
          return false;
        }

        // Mark SDL as initialized
        isInitialized = true;

        // Create the window
        window = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // Automatically center the window
                                  w, h,
                                  SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

        // Check for window creation failure
        if (window == nullptr) {
          std::cerr << "Unable to create window! SDL_Error: " << SDL_GetError() << std::endl;
          return false;
        }

        return true;
      }
    } // namespace Runtime
  } // namespace Engine
} // namespace Versis