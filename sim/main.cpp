#include <string>
#include <iostream>
#include <lunomath/lunomath.h>
#include "./Versis/Engine/Engine.hpp"

using namespace Versis::Engine::Runtime;

class Simulator : public App {
private: 
  mach_t machine;
public:
  Simulator() : App("Lunomath GUI", 1280, 720, false) {
    
    u8_t prog[32];

    machine = create_mach(prog, 32);
    int r = q_rand((int*)2112);
    printf("%08X %08X\n", angle_from_deg(F_TO_FX(211.2f)),
                          convert_angle_val(angle_from_deg(F_TO_FX(211.2f))));
  }

  void Step() override {
    char* output = catch_mach_err(&machine);
    if(output != NULL) {
      std::cout << output << std::endl;
    }
  }

};

int main(int argc, char* argv[]) {
  // Create a new instance of Simulator
  Simulator* app = new Simulator();
  
  // Initialize the app with a window title and size
  app->Start();

  //Versis::Engine::UI ui(app);

  // Main loop: keep handling events while the app state is true
  while (app->GetState()) {
    app->Handle();

    app->GetRenderer()->BeginRender();

    app->Step();

    app->GetRenderer()->Update();
  }
  
  // Delete the app object
  delete app;
  
  return 0;
}
