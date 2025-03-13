#pragma once
#ifndef _APP_HPP
#define _APP_HPP

#include "../Window/Window.hpp"
#include "../Module/Module.hpp"
#include "../Renderer/Renderer.hpp"
#include "../VideoComponent/VideoComponent.hpp"

#define SDL_MAIN_HANDLED
#undef main

namespace Versis {
  namespace Engine {
    namespace Runtime {
    class App : public Module, public VideoComponent {
      public:
        App::App( const char *title,
                  int         width,
                  int         height,
                  bool        vsync) {
          State         = false;
          WindowDriver  = new Window(   title,
                                        width,
                                        height);
          RenderDriver  = new Renderer( WindowDriver, vsync);
        }
      
        bool Start() override;

        // Handle SDL events
        void Handle();

        // To override...
        virtual void Step() {};

        // Rendering functions
        void  BeginRender() override;
        void  EndRender()   override;

        bool GetState() const;
        Renderer *GetRenderer() const;
        Window   *GetWindow()   const;
        
        ~App();
      private:
        struct {
          bool          State;
          SDL_Event     Event;
          Window       *WindowDriver;
          Renderer     *RenderDriver;
        };

        struct {  
          Uint32 StartTime;
          int    FrameCount;
          int    FPS;
          float  TimeElapsed;
        };  
      };
    };
  };
};
#endif //_APP_HPP
