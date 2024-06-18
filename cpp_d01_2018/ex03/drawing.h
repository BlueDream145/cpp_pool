/*
** EPITECH PROJECT, 2019
** drawing.h
** File description:
** @epitech.eu
*/

#ifndef drawing_
    #define drawing_

    #include <stdint.h>
	#include <stddef.h>

    typedef struct point_s {
        int x;
        int y;
    } point_t;

    // drawing.c
    void draw_square(uint32_t **img , const point_t *origin , size_t size , uint32_t color);

#endif /* drawing_ */