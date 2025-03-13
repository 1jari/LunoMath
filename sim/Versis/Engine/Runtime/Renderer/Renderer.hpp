#ifndef _RENDERER_HPP
#define _RENDERER_HPP

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "../Module/Module.hpp"
#include "../Window/Window.hpp"

namespace Versis {
  namespace Engine {
    namespace Runtime {
      class Renderer : public Module {
      public:
        Renderer(Window *window, bool vsync) : vsync(vsync), window(window) {};
        ~Renderer();

        bool Start() override;

        SDL_GLContext GetContext() const;

        // Rendering functions
        void BeginRender();
        void Update();

      private:
        bool SetupOpenGLAttributes();
        void InitializeOpenGLDefaults();
        bool CreateContext();

        SDL_GLContext OpenGL;  // OpenGL context
        bool    vsync;
        Window* window;   // Window handle
      };
    } // namespace Runtime
  } // namespace Engine
} // namespace Versis

#endif //_RENDERER_HPP
