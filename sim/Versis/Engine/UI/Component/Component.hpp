#ifndef _VERSIS_ENGINE_UI_COMPONENT_HPP
#define _VERSIS_ENGINE_UI_COMPONENT_HPP

namespace Versis {
  namespace Engine {
    namespace UI {
      class Component {
      public:
        virtual
        void OnCreate()   = 0;
        virtual
        void OnStep()     = 0;
        virtual
        void OnDraw()     = 0;
        virtual
        void OnDestroy()  = 0;
      };
    }
  }
}

#endif //_VERSIS_ENGINE_UI_COMPONENT_HPP