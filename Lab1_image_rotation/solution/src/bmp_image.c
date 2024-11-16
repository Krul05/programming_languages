//
// Created by maria on 27.10.2024.
//

#include "bmp_image.h"

enum read_status from_bmp( FILE* in, struct image* img )
{
    struct bmp_header header;

    if (fread(&header, sizeof(header), 1, in) != 1) {
        return READ_INVALID_BITS;
    }
    if (header.bOffBits != 54 || header.biSize != 40 || header.biBitCount != 24) {
        return READ_INVALID_HEADER;
    }

    if (create_image(img, header.biWidth, header.biHeight) != IMG_CREATE_OK)
    {
        free_image(img);
        return READ_CREATE_ERROR;
    }

    uint64_t sizeOfLineBytes = (img->width * 3 + 3) / 4 * 4;

    uint32_t trashBytes = 0;
    for (uint64_t l = 0; l < img->height; l++) {
        uint64_t offset = l * img->width;
        if (fread(img->data + offset, 3, img->width, in) != img->width)
        {
            free_image(img);
            return READ_INVALID_BITS;
        }
        if (fread(&trashBytes, 1, sizeOfLineBytes - img->width * 3, in) != sizeOfLineBytes - img->width * 3)
        {
            free_image(img);
            return READ_INVALID_BITS;
        }
    }


    return READ_OK;
}

enum write_status to_bmp( FILE* out, struct image const* img )
{
    struct bmp_header header;
    uint64_t sizeOfLineBytes = (img->width * 3 + 3) / 4 * 4;

    header.bfType = 0x4D42;
    header.bfileSize = sizeof(header) + sizeOfLineBytes * img->height;
    header.bfReserved = 0;
    header.bOffBits = 54;
    header.biSize = 40;
    header.biWidth = img->width;
    header.biHeight = img->height;
    header.biPlanes = 1;
    header.biBitCount = 24;
    header.biCompression = 0;
    header.biSizeImage = sizeOfLineBytes * img->height;
    header.biXPelsPerMeter = 0;
    header.biYPelsPerMeter = 0;
    header.biClrUsed = 0;
    header.biClrImportant = 0;

    if(fwrite(&header, sizeof(header), 1, out) < 1) return WRITE_ERROR;

    uint32_t trashBytes = 0;
    for(uint64_t l = 0; l < img->height; l++) {
        uint64_t offset = l * img->width;
        if(fwrite(img->data+offset, 3, img->width, out) != img->width) return WRITE_ERROR;
        if(fwrite(&trashBytes, 1, sizeOfLineBytes - img->width * 3, out) != sizeOfLineBytes - img->width * 3)  return WRITE_ERROR;
    }

    return WRITE_OK;
}

