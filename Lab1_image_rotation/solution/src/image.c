//
// Created by maria on 02.11.2024.
//
#include "image.h"
#include <stdlib.h>


enum image_status create_image(struct image* img, uint64_t w, uint64_t h)
{
    img->width = w;
    img->height = h;
    img->data = (struct pixel*) malloc(w * h * sizeof(struct pixel));

    if(!img->data) {
        free_image(img);
        return IMG_CREATE_ERROR;
    }
    return IMG_CREATE_OK;
}


void free_image(struct image* img)
{
    free(img->data);
}


struct pixel* get_pixel(struct image* img, uint64_t x, uint64_t y)
{
    if(x >= img->width || y >= img->height ) return NULL;

    return &(img->data[(y * img->width) + x]);
}
