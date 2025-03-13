#include "./Renderer.hpp"

namespace Versis {
  namespace Engine {
    namespace Runtime {
      // Start the renderer by setting up OpenGL context, GLAD, and V-Sync if necessary
      bool Renderer::Start() {
        // Set OpenGL attributes
        if (!SetupOpenGLAttributes()) {
          return false;
        }

        // Create OpenGL context
        OpenGL = SDL_GL_CreateContext(window->GetHandle());
        if (!OpenGL) {
          std::cerr << "Failed to create OpenGL context! SDL_Error: " << SDL_GetError() << std::endl;
          return false;
        }

        // Initialize GLAD (load OpenGL function pointers)
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(SDL_GL_GetProcAddress))) {
          std::cerr << "Failed to initialize GLAD! Error: " << std::endl;
          return false;
        }

        // Enable V-Sync if requested
        if (vsync) {
          if (SDL_GL_SetSwapInterval(1) < 0) {
            std::cerr << "Unable to set V-Sync! SDL_Error: " << SDL_GetError() << std::endl;
            return false;
          }
        }

        // Set default OpenGL states
        InitializeOpenGLDefaults();

        return true;
      }
      
      SDL_GLContext Renderer::GetContext() const {
        return OpenGL;
      }

      // Destructor to clean up OpenGL context
      Renderer::~Renderer() {
        if (OpenGL) {
          SDL_GL_DeleteContext(OpenGL); // Clean up OpenGL context
        }
      }

      // Setup OpenGL attributes (version and profile)
      bool Renderer::SetupOpenGLAttributes() {
        // Request OpenGL 3.3 core profile
        if (SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3) != 0 ||
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3) != 0 ||
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE) != 0) {
          std::cerr << "Failed to set OpenGL attributes! SDL_Error: " << SDL_GetError() << std::endl;
          return false;
        }
        return true;
      }

      // Set default OpenGL settings
      void Renderer::InitializeOpenGLDefaults() {
        // Set up the viewport
        glViewport(0, 0, window->GetWidth(), window->GetHeight());

        // Set clear color (RGBA)
        glClearColor(0.1f, 0.45f, 0.5f, 1.0f);

        // Enable depth testing
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
      }

      // Begin rendering by clearing the screen
      void Renderer::BeginRender() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen (color + depth buffer)
      }

      // Swap buffers to update the window with the rendered content
      void Renderer::EndRender() {
        SDL_GL_SwapWindow(window->GetHandle());
      }

    } // namespace Runtime
  } // namespace Engine
} // namespace Versis
