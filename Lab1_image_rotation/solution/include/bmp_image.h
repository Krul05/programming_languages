//
// Created by maria on 27.10.2024.
//

#ifndef IMAGE_TRANSFORMER_BMP_IMAGE_H
#define IMAGE_TRANSFORMER_BMP_IMAGE_H
#include "image.h"
#include "statuses.h"
#include <stdio.h>

#pragma pack(push, 1)
struct bmp_header
{
    uint16_t bfType;
    uint32_t  bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t  biHeight;
    uint16_t  biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t  biClrImportant;
};
#pragma pack(pop)


enum read_status from_bmp( FILE* in, struct image* img );
enum write_status to_bmp( FILE* out, struct image const* img );

#endif //IMAGE_TRANSFORMER_BMP_IMAGE_H