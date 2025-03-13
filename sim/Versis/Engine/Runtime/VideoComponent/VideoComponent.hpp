#ifndef _VERSIS_ENGINE_RUNTIME_VIDEOCOMPONENT_HPP
#define _VERSIS_ENGINE_RUNTIME_VIDEOCOMPONENT_HPP

namespace Versis {
  namespace Engine {
    namespace Runtime {
      class VideoComponent {
      public:
        // Default constructor
        VideoComponent()          = default;

        virtual
        void BeginRender()        = 0;
        virtual
        void EndRender()          = 0;

        // Virtual destructor to ensure proper cleanup of derived classes
        virtual ~VideoComponent() = default;
      };

    } // namespace Runtime
  } // namespace Engine
} // namespace Versis

#endif //_VERSIS_ENGINE_RUNTIME_VIDEOCOMPONENT_HPP