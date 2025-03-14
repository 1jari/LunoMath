#include "./Shader.hpp"

namespace Versis {
  namespace Engine {
    namespace UI {
      // Utility function to log OpenGL errors
      void CheckShaderCompilation(GLuint shader) {
        GLint success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (success != GL_TRUE) {
          GLint logLength;
          glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
          std::vector<char> log(logLength);
          glGetShaderInfoLog(shader, logLength, nullptr, log.data());
          std::cerr << "Shader compilation failed: " << log.data() << std::endl;
          glDeleteShader(shader);
          throw std::runtime_error("Shader compilation failed.");
        }
      }

      // Utility function to log OpenGL program linking errors
      void CheckProgramLinking(GLuint program) {
        GLint success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (success != GL_TRUE) {
          GLint logLength;
          glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
          std::vector<char> log(logLength);
          glGetProgramInfoLog(program, logLength, nullptr, log.data());
          std::cerr << "Program linking failed: " << log.data() << std::endl;
          glDeleteProgram(program);
          throw std::runtime_error("Program linking failed.");
        }
      }

      // Function to compile shader from source code
      GLuint CompileShader(const char* src, GLenum shaderType) {
        GLuint shader = glCreateShader(shaderType);
        glShaderSource(shader, 1, &src, nullptr);
        glCompileShader(shader);
        CheckShaderCompilation(shader);
        return shader;
      }

      // Function to create a shader program from vertex and fragment shaders
      GLuint CreateShaderProgram(GLuint vertexShader, GLuint fragmentShader) {
        GLuint program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);
        CheckProgramLinking(program);
        return program;
      }

      // Function to generate a vertex array object (VAO), vertex buffer object (VBO), and element buffer object (EBO)
      GLuint GenerateVertexObjects(const std::vector<float>& vertices,
                const std::vector<GLuint>& indices,
                const std::vector<int>& attributeSizes) {
        GLuint VAO, VBO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        // Upload vertex data to the VBO
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        // Upload index data to the EBO
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

        // Calculate stride to set vertex attribute pointers
        int stride = 0;
        for (int size : attributeSizes) {
          stride += size;
        }

        GLuint offset = 0;
        for (size_t i = 0; i < attributeSizes.size(); ++i) {
          glVertexAttribPointer(i, attributeSizes[i], GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
          glEnableVertexAttribArray(i);
          offset += attributeSizes[i];
        }

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        return VAO;
      }

    } 
  }
}