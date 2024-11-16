//
// Created by maria on 30.10.2024.
//

#include "file.h"


reading readings[] = {
        [BMP] = from_bmp,
};
writing writings[] = {
        [BMP] = to_bmp,
};

enum formats found_format_reading(FILE* f) {
    enum formats format = NONE;
    uint16_t type;
    fread(&type, sizeof(type), 1, f);
    fseek(f, 0, SEEK_SET);
    switch (type) {
        case (0x4D42): {format = BMP; break;}
        default: {}
    }
    return format;
}

enum formats found_format_writing(const char* f) {
    enum formats format = NONE;
    char* type = (strrchr(f, '.')+2);
    printf("%d", strcmp(type, "bmp"));
    if (strcmp(type, "bmp") != 0) {
        format = BMP;
    }
    return format;
}


enum read_status read_file(const char* fileName, struct image* img) {
    FILE* f;
    f = fopen(fileName, "rb");
    enum formats format = found_format_reading(f);
    if (format == NONE) {
        return READ_INVALID_SIGNATURE;
    }
    if (!f) return READ_ERROR_OPEN_FILE;
    enum read_status rs = readings[format](f, img);
    fclose(f);

    return rs;
}

enum write_status write_file(const char* fileName, struct image* img) {
    FILE* f;
    f = fopen(fileName, "wb");
    enum formats format = found_format_writing(fileName);
    if (format == NONE) {
        return WRITE_INVALID_FORMAT;
    }
    if (!f) {
        return WRITE_FILE_OPEN_ERROR;
    }
    enum write_status ws = writings[format](f, img);
    fclose(f);
    return ws;
}
