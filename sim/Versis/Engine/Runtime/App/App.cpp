#include "./App.hpp"

namespace Versis {
  namespace Engine {
    namespace Runtime {
      bool App::Start() {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
          printf("SDL Initialization failed!\n");
          return false;
        }

        if(!WindowDriver->Start()) {
          std::cerr << "Unable to Start Window!" << std::endl;
          return false;
        }
        
        if(!RenderDriver->Start()) {
          std::cerr << "Unable to Start Renderer!" << std::endl;
          return false;
        }
        State       = true;
        StartTime   = SDL_GetTicks64();
        FrameCount  = 0;
        FPS         = 0;
        return true;
      }

      void App::Handle() {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch(event.type) {
        case SDL_QUIT:
          SDL_Quit();
          State = false;
          break;
        default:
          break;
        }
      }

      void App::BeginRender() {
        RenderDriver->BeginRender();
      }
      void App::EndRender() {
        RenderDriver->EndRender();
      }

      Renderer *App::GetRenderer() const {
        return RenderDriver;
      }
      
      Window   *App::GetWindow()   const {
        return WindowDriver;
      }
      bool App::GetState() const {
        return State;
      }
      
      App::~App() {
        delete  RenderDriver;
        delete  WindowDriver;
        printf("Done!\n");
      }
    };
  };
};
