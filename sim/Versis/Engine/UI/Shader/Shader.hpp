#ifndef _VERSIS_ENGINE_UI_RUNTIME_SHADER_HPP
#define _VERSIS_ENGINE_UI_RUNTIME_SHADER_HPP

#include <string>
#include <iostream>
#include <GL/glad.h>
#include <vector>
#include <GL/gl.h> 

#define   DEFAULT_VERTEX_SHADER_SRC (R"(#version 330 core in vec2 vertex;void main(){gl_Position=vec4(vertex, 0.0, 1.0);})")
#define   DEFAULT_FRAG_SHADER_SRC   (R"(#version 330 core out vec4 color;void main(){color=vec4(1.0f, 0.5f, 0.2f, 1.0);})")
#define   DEFAULT_VERTEX_SHADER     (Versis::Engine::UI::CompileShader(DEFAULT_VERTEX_SHADER_SRC, GL_VERTEX_SHADER))
#define   DEFAULT_FRAG_SHADER       (Versis::Engine::UI::CompileShader(DEFAULT_FRAG_SHADER_SRC, GL_FRAGMENT_SHADER))
#define   DEFAULT_SHADER_PROGRAM    (Versis::Engine::UI::CreateShaderProgram(DEFAULT_VERTEX_SHADER, DEFAULT_FRAG_SHADER))

namespace Versis {
  namespace Engine {
    namespace UI {
    
      GLuint CompileShader(         const
                                    char*                 src, 
                                    GLenum                kind);

      GLuint CreateShaderProgram(   GLuint                vertexShader, 
                                    GLuint                fragmentShader);

      GLuint GenerateVertexObjects( const
                                    std::vector<float>&   vertices, 
                                    const
                                    std::vector<GLuint>&  indices, 
                                    const
                                    std::vector<int>&     attributeSizes); 
    }
  }
}
#endif //_VERSIS_ENGINE_UI_RUNTIME_SHADER_HPP