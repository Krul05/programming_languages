//
// Created by maria on 27.10.2024.
//

#ifndef IMAGE_TRANSFORMER_IMAGE_H
#define IMAGE_TRANSFORMER_IMAGE_H

#include  <stdint.h>
struct pixel { uint8_t b, g, r; };
struct image {
    uint64_t width, height;
    struct pixel* data;
};

enum image_status {
    IMG_CREATE_OK = 0,
    IMG_CREATE_ERROR,
};

enum image_status create_image(struct image* img, uint64_t w, uint64_t h);

void free_image(struct image* img);

struct pixel* get_pixel(struct image* img, uint64_t x, uint64_t y);

#endif //IMAGE_TRANSFORMER_IMAGE_H
