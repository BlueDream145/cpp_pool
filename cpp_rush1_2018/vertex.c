/*
** EPITECH PROJECT, 2019
** cpp_rush1_2018
** File description:
** vertex
*/

#include <string.h>
#include <stdio.h>
#include "vertex.h"
#include "point.h"
#include "new.h"

#define KEY (10 * 3 + 16 + 1)

typedef struct
{
    Class   base;
    int     x;
    int     y;
    int     z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!(this) || !(args))
        raise("Wrong pointer");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

static const char *Vertex_str(VertexClass *this)
{
    static char res[KEY] = { 0 };

    if (!(this))
        raise("Wrong pointer");
    snprintf(res, KEY, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (strdup(res));
}

static Object *Vertex_add(const Object *this, const Object *obj)
{
    VertexClass *res = NULL;
    VertexClass *_this = (VertexClass *)(this);
    VertexClass *_obj = (VertexClass *)(obj);
    int x, y, z;

    if (!(_this) || !(_obj))
        raise("Wrong pointer");
    x = _this->x + _obj->x;
    y = _this->y + _obj->y;
    z = _this->z + _obj->z;
    res = new(Vertex, x, y ,z);
    return (res);
}

static Object *Vertex_sub(const Object *this, const Object *obj)
{
    VertexClass *res = NULL;
    VertexClass *_this = (VertexClass *)(this);
    VertexClass *_obj = (VertexClass *)(obj);
    int x, y, z;

    if (!(_this) || !(_obj))
        raise("Wrong pointer");
    x = _this->x - _obj->x;
    y = _this->y - _obj->y;
    z = _this->z - _obj->z;
    res = new(Vertex, x, y ,z);
    return (res);
}

static VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

Class *Vertex = (Class *)&_description;
