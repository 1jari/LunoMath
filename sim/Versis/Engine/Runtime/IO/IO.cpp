#include "./IO.hpp"

namespace Versis {
  namespace Engine {
      namespace Runtime {
      // Read the entire file and return its content as a string
      std::string ReadFile(const std::string& filename) {
        char cwd[256];
          if (_getcwd(cwd, sizeof(cwd)) != NULL) {
            std::cout << "Current working directory: " << cwd << std::endl;
          } else {
            std::cerr << "_getcwd() failed" << std::endl;
          }

        std::ifstream file(filename);  // Open file
        if (!file) {  // Check if file is open
          std::cerr << "Could not open the file: " << filename << std::endl;
          return "";  // Return empty string if file couldn't be opened
        }

        std::stringstream buffer;
        buffer << file.rdbuf();  // Read the file into the stringstream buffer
        return buffer.str();  // Return the file contents as a string
      }

    }
  }
}