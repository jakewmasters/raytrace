#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>

void
write_ppm(char *out_file)
{
    FILE *out_file_ptr;
    if ((out_file_ptr = fopen(out_file, "w")) == NULL) {
        fprintf(stderr, "can't open %s for reading...\n", out_file);
        exit(1);
    }

    fprintf(out_file_ptr, "P3\n3 2\n1\n");
    fprintf(out_file_ptr, "1 0 0   0 1 0   0 0 1\n");
    fprintf(out_file_ptr, "1 1 0   1 1 1   0 0 0\n");

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

    // int nx = 200;
    // int ny = 200;
    write_ppm(out_file);
}