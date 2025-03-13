#ifndef _VERSIS_MODELS_ANGLE_HPP
#define _VERSIS_MODELS_ANGLE_HPP

#include "../../Engine/UI/UI.hpp"

namespace Versis {
  namespace Models {
    class Angle : public Engine::UI::Component {
    public:
      virtual
      void OnCreate()   override {}
      virtual
      void OnStep()     override {}
      virtual
      void OnDraw()     override {}
      virtual
      void OnDestroy()  override {}
    };
  }
}

#endif //_VERSIS_MODELS_ANGLE_HPP