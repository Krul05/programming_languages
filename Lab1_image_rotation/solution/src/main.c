#include "file.h"
#include "rotate_image.h"
int main( int argc, char** argv ) {
    (void) argc; (void) argv; // supress 'unused parameters' warning
    if (argc == 3)
    {
        struct image img;
        struct image rotatedImg;

        if (read_file(argv[1], &img) != READ_OK)
        {
            printf("Read file error\n");
            return 0;
        }

        rotatedImg = rotate(img);

        if (rotatedImg.data == img.data)
        {
            free_image(&img);
            printf("Rotate image error\n");
            return 0;
        }

        if (write_file(argv[2], &rotatedImg) != WRITE_OK)
        {
            free_image(&img);
            free_image(&rotatedImg);
            printf("Write file error\n");
            return 0;
        }

        free_image(&img);
        free_image(&rotatedImg);
    } else {
        printf("Use command './image-transformer <source-image> <transformed-image>'");
    }
    return 0;
}
