#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include <math.h>

// #include "vec3.h"
#include "ray.h"

#ifndef VEC3
    #define VEC3
    //code
#endif

float
hit_sphere(vec3 center, float radius, ray r)
{
    vec3 oc = vec3_subtract(ray_origin(r), center);
    float a = vec3_dot(ray_direction(r), ray_direction(r));
    float b = 2.0 * vec3_dot(oc, ray_direction(r));
    float c = vec3_dot(oc, oc) - (radius * radius);
    float discriminant = (b*b) - 4*a*c;
    if (discriminant < 0){
        return -1.0;
    } else {
        return (-b - sqrt(discriminant))/(2.0*a);
    }
}

vec3
color(ray r)
{
    // ch 5
    // ch 4
    vec3 center = vec3_init(0.0, 0.0, -1.0);
    float t = hit_sphere(center, 0.5, r);
    if (t > 0.0){
        vec3 N = vec3_subtract(ray_point_at_param(r, t), center);
        N = vec3_unit_vector(N);
        return vec3_scale_multiply(vec3_init(N.x+1.0,N.y+1.0,N.z+1.0), 0.5);
    }
    // ch 3
    vec3 unit_direction = vec3_unit_vector(ray_direction(r));
    t = 0.5*(unit_direction.y + 1.0);
    vec3 v1 = vec3_init(1.0, 1.0, 1.0);
    v1 = vec3_scale_multiply(v1, (1.0-t));
    vec3 v2 = vec3_init(0.5, 0.7, 1.0);
    v2 = vec3_scale_multiply(v2, t);
    return vec3_add(v1, v2);
}

void
write_ppm(char *out_file, int nx, int ny)
{
    FILE *out_file_ptr;
    if ((out_file_ptr = fopen(out_file, "w")) == NULL) {
        fprintf(stderr, "can't open %s for reading...\n", out_file);
        exit(1);
    }

    vec3 lower_left_corner = vec3_init(-2.0, -1.0, -1.0);
    vec3 horizontal = vec3_init(4.0, 0.0, 0.0);
    vec3 vertical = vec3_init(0.0, 2.0, 0.0);
    vec3 origin = vec3_init(0.0, 0.0, 0.0);

    fprintf(out_file_ptr, "P3\n%d %d\n255\n", nx, ny);
    for (int j=ny-1; j >=0; --j){
        for (int i=0; i < nx; ++i){
            float u = (float)i / (float)nx;
            float v = (float)j / (float)ny;

            vec3 direction = vec3_add(lower_left_corner, vec3_scale_multiply(horizontal, u));
            direction = vec3_add(direction, vec3_scale_multiply(vertical, v));
            ray r = ray_init(origin, direction);
            vec3 col = color(r);

            int ir = (int)(255.99*col.x);
            int ig = (int)(255.99*col.y);
            int ib = (int)(255.99*col.z);
            fprintf(out_file_ptr, "%d %d %d\n", ir, ig, ib);
        }
    }

    fclose(out_file_ptr);
}

void
usage(char *prog_name)
{
    fprintf(stderr, "%s: [-h] -o <out_file>...\n", prog_name);
    fprintf(stderr, "  -o        exactly one output file must be specified\n");
    fprintf(stderr, "  -h        print this help and exit\n");
}

int 
main(int argc, char **argv)
{
    char *prog_name = argv[0];
    char *out_file;
    
    int ch;
    while ((ch = getopt(argc, argv, "ho:")) != -1) {
        switch(ch) {
            case 'o':
                out_file = optarg;
                break;
            case '?':
            default:
                usage(prog_name);
        }
    }

    int nx = 4000;
    int ny = 2000;
    write_ppm(out_file, nx, ny);

    // got through chapter 1 of Raytracing in a Weekend!
    // chapter 2 implemented **as needed**
    // finished chapter 3!
    // finished chapter 4!
    // halfway through chapter 5
}