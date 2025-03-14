#ifndef _VERSIS_ENGINE_UI_SHAPES_SHAPE_HPP
#define _VERSIS_ENGINE_UI_SHAPES_SHAPE_HPP

#include <GL/glad.h>
#include <iostream>

namespace Versis {
  namespace Engine {
    namespace UI {
      namespace Shapes {
        class Shape {
        protected:
          GLuint VAO, 
                 VBO, 
                 EBO;  // Element Buffer Object (Optional if using indices)
          GLfloat  *Vertices;
          int       VerticesSize;
        public:
          Shape(GLfloat *Vertices, int VerticesSize) : Vertices(Vertices), VerticesSize(VerticesSize) {
            if (VerticesSize == 0) {
              std::cerr << "Vertices Index is null" << std::endl;
              return;
            }

            // Generate the VAO, VBO, and optionally EBO
            glGenVertexArrays(1, &VAO);
            glGenBuffers(1, &VBO);

            glBindVertexArray(VAO);

            // Create and bind the VBO for vertex data
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, VerticesSize * sizeof(float), Vertices, GL_STATIC_DRAW);

            // Define vertex attributes (assuming each vertex has a position of 3 components)
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);

            // Unbind VAO and VBO
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
          }

          // Virtual destructor to ensure proper cleanup in derived classes
          virtual ~Shape() {
            glDeleteVertexArrays(1, &VAO);
            glDeleteBuffers(1, &VBO);
          }

          // Method to draw the shape
          void Draw(GLfloat x,
                    GLfloat y) {
            glLoadIdentity();
            glTranslatef(x, y, 0.0f);
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, VerticesSize / 3);  // Use VerticesSize to calculate number of vertices
            glBindVertexArray(0);
          }
        };
      }
    }
  }
}

#endif //_VERSIS_ENGINE_UI_SHAPES_SHAPE_HPP
