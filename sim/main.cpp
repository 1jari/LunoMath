#include <string>
#include <vector>
#include <iostream>
#include <lunomath/lunomath.h>
#include "./Versis/Versis.hpp"

using namespace Versis::Engine::Runtime;
using namespace Versis::Engine::UI;

class Simulator : public App {
public:
  Simulator() : App("Lunomath GUI", 1280, 720, false) {
  }

  void Step() override {
  }
};

int main(int argc, char* argv[]) {
  Simulator* app = new Simulator();
  
  app->Start();

  Shapes::Triangle shape(0.7f);

  while (app->GetState()) {
    app->GetRenderer()->BeginRender(); 

    // Process user input/events
    app->Handle();

    // Perform necessary application logic
    app->Step();


    shape.GetShape()->Draw(0.5f, 0.5f);
    app->GetRenderer()->EndRender(); // Finish rendering frame
  }

  // Clean up and exit
  delete app;
  return 0;
}
