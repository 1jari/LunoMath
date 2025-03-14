#ifndef _VERSIS_ENGINE_UI_SHAPES_TRIANGLE_HPP
#define _VERSIS_ENGINE_UI_SHAPES_TRIANGLE_HPP

#include <iostream>
#include <GL/glad.h>

#include "../Shape/Shape.hpp"

namespace Versis {
  namespace Engine {
    namespace UI {
      namespace Shapes {
        class Triangle {
        public:
          Triangle(float size) {
            GLfloat vertices[] = {
              -size, -size, size, 
               size, -size, size,
               size,  size, size
            };
            shape = new Shape(vertices, 9);
          } 
          Shape *GetShape() const {
            return shape;
          }
         ~Triangle() {
            delete shape;
          }
        private:
          Shape *shape;
        };
      }
    }
  }
}

#endif //_VERSIS_ENGINE_UI_SHAPES_TRIANGLE_HPP
