#ifndef _RENDERER_HPP
#define _RENDERER_HPP

#include <SDL2/SDL.h>
#include <GL/glad.h>
#include "../Module/Module.hpp"
#include "../Window/Window.hpp"
#include "../VideoComponent/VideoComponent.hpp"

#define GLSL_VERSION "#version 130"

namespace Versis {
  namespace Engine {
    namespace Runtime {
      class Renderer : public Module, public VideoComponent {
      public:
        Renderer(Window *window, bool vsync) : vsync(vsync), window(window) {};
        ~Renderer();

        bool Start() override;

        SDL_GLContext GetContext() const;

        // Rendering functions
        void  BeginRender() override;
        void  EndRender()   override;

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
