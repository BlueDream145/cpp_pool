/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <string.h>
#include <stdio.h>
#include "point.h"
#include "new.h"

#define KEY (12 + 10 * 2 + 1)

typedef struct
{
    Class   base;
    int     x;
    int     y;
} PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!(this) || !(args))
        raise("Wrong pointer");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void)this;
}

static const char *Point_str(PointClass *this)
{
    static char res[KEY];

    if (!(this))
        raise("Wrong pointer");
    snprintf(res, KEY, "<Point (%d, %d)>", this->x, this->y);
    return (strdup(res));
}

static Object *Point_add(const Object *this, const Object *obj)
{
    PointClass *res = NULL;
    PointClass *_this = (PointClass *)(this);
    PointClass *_obj = (PointClass *)(obj);
    int x, y;

    if (!(_this) || !(_obj))
        raise("Wrong pointer");
    x = _this->x + _obj->x;
    y = _this->y + _obj->y;
    res = new(Point, x, y);
    return (res);
}

static Object *Point_sub(const Object *this, const Object *obj)
{
    PointClass *res = NULL;
    PointClass *_this = (PointClass *)(this);
    PointClass *_obj = (PointClass *)(obj);
    int x, y;

    if (!(_this) || !(_obj))
        raise("Wrong pointer");
    x = _this->x - _obj->x;
    y = _this->y - _obj->y;
    res = new(Point, x, y);
    return (res);
}

static PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

Class *Point = (Class *)&_description;
