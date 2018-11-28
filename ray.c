#include "vec3.h"

typedef struct {
    vec3 origin;
    vec3 direction;
} ray;

ray
ray_init(vec3 a, vec3 b)
{
    ray ret_ray;
    ret_ray.origin = a;
    ret_ray.direction = b;
    return ret_ray;
}

vec3
ray_origin(ray r)
{
    return r.origin;
}

vec3
ray_direction(ray r)
{
    return r.direction;
}

vec3
ray_point_at_param(ray r, float t)
{
    vec3 scale = vec3_scale_multiply(r.direction, t);
    return vec3_add(r.origin, scale);
}