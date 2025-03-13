#ifndef _VERSIS_ENGINE_RUNTIME_MODULE_HPP
#define _VERSIS_ENGINE_RUNTIME_MODULE_HPP

namespace Versis {
  namespace Engine {
    namespace Runtime {

      class Module {
      public:
        // Default constructor
        Module() = default;

        // Virtual start method, should be overridden by derived classes
        virtual bool Start() = 0; // Pure virtual function

        // Virtual destructor to ensure proper cleanup of derived classes
        virtual ~Module() = default;
      };

    } // namespace Runtime
  } // namespace Engine
} // namespace Versis

#endif //_VERSIS_ENGINE_RUNTIME_MODULE_HPP