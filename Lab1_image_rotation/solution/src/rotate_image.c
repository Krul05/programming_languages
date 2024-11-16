//
// Created by maria on 02.11.2024.
//
#include "image.h"
struct image rotate(struct image source)
{
    struct image rotatedImg;

    if (create_image(&rotatedImg, source.height, source.width) != IMG_CREATE_OK)
    {
        return source;
    }

    for (uint64_t x = 0; x < rotatedImg.width; x++)
    {
        for (uint64_t y = 0; y < rotatedImg.height; y++)
        {
            *get_pixel(&rotatedImg, rotatedImg.width - x - 1, y) = *get_pixel(&source, y, x);
        }
    }
    return rotatedImg;
}
