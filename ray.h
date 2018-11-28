#include "vec3.h"

typedef struct {
    vec3 A;
    vec3 B;
} ray;

extern ray ray_init(vec3 a, vec3 b);
extern vec3 ray_origin(ray r);
extern vec3 ray_direction(ray r);
extern vec3 ray_point_at_param(ray r, float t);