//
// Created by maria on 14.11.2024.
//

#ifndef IMAGE_TRANSFORMER_STATUSES_H
#define IMAGE_TRANSFORMER_STATUSES_H
/*  deserializer   */
enum read_status  {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER,
    READ_ERROR_OPEN_FILE,
    READ_CREATE_ERROR,
};

/*  serializer   */
enum  write_status  {
    WRITE_OK = 0,
    WRITE_ERROR,
    WRITE_INVALID_FORMAT,
    WRITE_FILE_OPEN_ERROR,
    /* коды других ошибок  */
};
#endif //IMAGE_TRANSFORMER_STATUSES_H
