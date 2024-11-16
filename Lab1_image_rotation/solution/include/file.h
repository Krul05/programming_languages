//
// Created by maria on 27.10.2024.
//

#ifndef IMAGE_TRANSFORMER_FILE_H
#define IMAGE_TRANSFORMER_FILE_H
#include "bmp_image.h"
#include <string.h>


enum formats {
    BMP,
    NONE,
};


enum formats found_format_reading(FILE* f);
enum formats found_format_writing(const char* f);
typedef enum  read_status (*reading)(FILE* in, struct image* img);
typedef enum  write_status (*writing)(FILE* out, struct image const* img);
enum read_status read_file(const char* fileName, struct image* img);
enum write_status write_file(const char* fileName, struct image* img);
#endif //IMAGE_TRANSFORMER_FILE_H
