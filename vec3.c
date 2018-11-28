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

vec3
vec3_subtract(vec3 v1, vec3 v2)
{
    vec3 ret_vec;
    ret_vec.x = v1.x - v2.x;
    ret_vec.y = v1.y - v2.y;
    ret_vec.z = v1.z - v2.z;
    return ret_vec;
}

vec3
vec3_divide(vec3 v1, vec3 v2)
{
    vec3 ret_vec;
    ret_vec.x = v1.x / v2.x;
    ret_vec.y = v1.y / v2.y;
    ret_vec.z = v1.z / v2.z;
    return ret_vec;
}

vec3
vec3_scale_multiply(vec3 v, float t)
{
    v.x *= t;
    v.y *= t;
    v.z *= t;
    return v;
}

vec3
vec3_scale_divide(vec3 v, float t)
{
    v.x /= t;
    v.y /= t;
    v.z /= t;
    return v;
}

float
vec3_dot(vec3 v1, vec3 v2)
{
    return (v1.x * v2.x) + (v1.y * v1.y) + (v1.z * v2.z);
}

float
vec3_length(vec3 v)
{
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

vec3
vec3_unit_vector(vec3 v)
{
    float length = vec3_length(v);
    return vec3_scale_divide(v, length);
}