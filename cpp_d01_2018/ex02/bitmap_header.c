/*
** EPITECH PROJECT, 2019
** bitmap_header.c
** File description:
** @epitech.eu
*/

#include "bitmap.h"

void make_bmp_header(bmp_header_t *header, size_t size)
{
    #if __BYTE_ORDER__ == ORDER_LITTLE_ENDIAN
        header->magic = 0x424D;
    #else
        header->magic = 0x424d;
    #endif
    header->size = (size * size * 4) + (sizeof(bmp_header_t)) +
        (sizeof(bmp_info_header_t));
    header->_app1 = 0;
    header->_app2 = 0;
    header->offset = sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
}

void make_bmp_info_header(bmp_info_header_t *info_header, size_t size)
{
    info_header->size = sizeof(bmp_info_header_t);
    info_header->width = size;
    info_header->height = size;
    info_header->planes = 1;
    info_header->bpp = 32;
    info_header->compression = 0;
    info_header->raw_data_size = size * size * 4;
    info_header->h_resolution = 0;
    info_header->v_resolution = 0;
    info_header->palette_size = 0;
    info_header->important_colors = 0;
}