#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
    float z;
} vec3;

vec3
vec3_init(float x, float y, float z)
{
    vec3 ret_vec;
    ret_vec.x = x;
    ret_vec.y = y;
    ret_vec.z = z;
    return ret_vec;
}

vec3
vec3_add(vec3 v1, vec3 v2)
{
    vec3 ret_vec;
    ret_vec.x = v1.x + v2.x;
    ret_vec.y = v1.y + v2.y;
    ret_vec.z = v1.z + v2.z;
    return ret_vec;
}