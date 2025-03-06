#include <lunomath/lunomath.h>
#include "./Runtime/App/App.hpp"

q_stack_t stack;

using namespace Runtime;

class Simulator : public App {
public:
  Simulator() : App() {
    stack = create_q_stack();
    
    u8_t prog[32];

    machine = create_mach(prog, 32);

    // Corrected: angle_from_deg(45.0f) for converting degrees to internal representation
    angle_t angle = angle_from_deg(F_TO_FX(45.0f));

    vec2f_t v = vec2f(F_TO_FX(21.12f), F_TO_FX(19.11f));
    vec2f_t nv = apply_angle_vec2f(angle, v);

    printf("random %d\n", q_rand((int*)2112));

    printf("x: %f\n", FX_TO_F(vec2f_get_x(v)));
    printf("y: %f\n", FX_TO_F(vec2f_get_y(v)));
    printf("---------\n", v);

    printf("x: %f\n", FX_TO_F(vec2f_get_x(nv)));
    printf("y: %f\n", FX_TO_F(vec2f_get_y(nv)));
  }

  void step() override {}

  void draw() override {}

  ~Simulator() {
    clean_q_stack(&stack);
    shutdown_mach(&machine);
  }
  private: 
    mach_t machine;
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
