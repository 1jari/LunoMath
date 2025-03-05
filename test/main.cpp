#include "./Runtime/App/App.hpp"

using namespace Runtime;

class Simulator : public App {
public:
  Simulator() : App() {} // Make the constructor public

  void step() override {}
  void draw() override {}

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
