#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include <math.h>
#include "vec3.h"

void
write_ppm(char *out_file, int nx, int ny)
{
    FILE *out_file_ptr;
    if ((out_file_ptr = fopen(out_file, "w")) == NULL) {
        fprintf(stderr, "can't open %s for reading...\n", out_file);
        exit(1);
    }

    fprintf(out_file_ptr, "P3\n%d %d\n255\n", nx, ny);
    for (int j=ny-1; j >=0; --j){
        for (int i=0; i < nx; ++i){
            float r = (float)i / (float)nx;
            float g = (float)j / (float)ny;
            float b = 0.2;
            int ir = (int)(255.99*r);
            int ig = (int)(255.99*g);
            int ib = (int)(255.99*b);
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

    int nx = 200;
    int ny = 100;
    write_ppm(out_file, nx, ny);

    // got through chapter 1 of Raytracing in a Weekend!
}