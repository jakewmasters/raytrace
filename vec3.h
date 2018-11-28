typedef struct {
    float x;
    float y;
    float z;
} vec3;

extern vec3 vec3_init(float x, float y, float z);
extern vec3 vec3_add(vec3 v1, vec3 v2);
extern vec3 vec3_divide(vec3 v1, vec3 v2);
extern vec3 vec3_scale_multiply(vec3 v, float t);
extern vec3 vec3_scale_divide(vec3 v, float t);
extern float vec3_length(vec3 v);
extern vec3 vec3_unit_vector(vec3 v);