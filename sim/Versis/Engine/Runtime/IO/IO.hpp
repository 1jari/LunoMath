#ifndef _VERSIS_ENGINE_RUNTIME_RUNTIME_IO_HPP
#define _VERSIS_ENGINE_RUNTIME_RUNTIME_IO_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <direct.h>

namespace Versis {
  namespace Engine {
    namespace Runtime {
      std::string ReadFile(const std::string& filename);
    }
  }
}

#endif //_VERSIS_ENGINE_RUNTIME_RUNTIME_IO_HPP