#include "./Runtime/App/App.hpp"
#include <lunomath/lunomath.h>

q_stack_t stack;

using namespace Runtime;

class Simulator : public App {
public:
  Simulator() : App() {
    stack = create_stack();
    stack_push(2112, &stack);
    
    // Corrected: angle_from_deg(45.0f) for converting degrees to internal representation
    int angle = angle_from_deg(F_TO_FX(211.2f));
    
    // Accessing the cosine value at the correct angle (assuming cos_table is already defined)
    fixed_t cos_val = cos_table[angle];
    
    // Print the angle, its internal representation, and the cosine value in hex format
    printf("vv %f - cos %x %f\n", 211.2f, angle_to_deg(angle), FX_TO_F(cos_val));
  }

  void step() override {}

  void draw() override {}

  ~Simulator() {
    clean_stack(&stack);
  }
};

int SDL_main(int argc, char* argv[]) {
  // Create a new instance of Simulator
  Simulator* app = new Simulator();
  
  // Initialize the app with a window title and size
  app->init("Lunomath Simulator", 1280, 720, false);

  // Main loop: keep handling events while the app state is true
  while (app->getState()) {
    app->handle();

    app->beginRender();

    app->step();
    
    app->endRender();
  }

  // Clean up resources when the loop ends
  app->clean();
  
  // Delete the app object
  delete app;
  
  return 0;
}
