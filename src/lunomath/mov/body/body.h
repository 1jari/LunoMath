#ifndef __BODY_H__
#define __BODY_H__

#include "../../gm/gm.h"
#include "../../mgmt/mgmt.h"

typedef union {
  vec2f_t   v2;
  axis_t    ax;
  angle_t   ang;
  line_t    ln;
  vertex_t  vt;
} obj_u;

typedef struct {
  
  struct {
    obj_u *obj;
    int    n_obj;
  };

  axis_t    c_axis; // Central axis
  vec2f_t   sz;     // Total size
} body_t;

LUNOMATH_API static
body_t create_body( axis_t c_axis,
                    vec2f_t  sz) {
  body_t body;
  body.c_axis = c_axis;
  body.sz     = sz;
  return body;
}

LUNOMATH_API static
void  destroy_body( body_t *body) {
  if(body->obj) {
    free(body->obj);
  }
}

#endif //__BODY_H__