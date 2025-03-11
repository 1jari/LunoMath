#include <string>
#include <iostream>
#include <lunomath/lunomath.h>
#include "./Runtime/App/App.hpp"

q_stack_t stack;

using namespace Runtime;

class Simulator : public App {
private: 
  mach_t machine;
public:
  Simulator() : App() {
    stack = create_q_stack();
    
    u8_t prog[32];

    machine = create_mach(prog, 32);
  }

  void step() override {
    char* output = catch_mach_err(&machine);
    if(output != NULL) {
      std::cout << output << std::endl;
    }
  }

  void draw() override {}

  ~Simulator() {
    clean_q_stack(&stack);
    shutdown_mach(&machine);
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
