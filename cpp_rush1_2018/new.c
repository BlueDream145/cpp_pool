/*
** EPITECH PROJECT, 2019
** cpp_rush1_2018
** File description:
** new
*/

#include <stdlib.h>
#include <string.h>
#include "new.h"

Object *new(Class *class, ...)
{
    Object *obj;
    va_list list;

    if (!(class))
        raise("No class given");
    va_start(list, class);
    obj = va_new(class, &list);
    va_end(list);
    return (obj);
}

Object *va_new(Class *class, va_list* list)
{
    Class *obj = NULL;

    if (!(class))
        raise("No class given");
    if (!(class->__size__))
        raise("No object size given");
    obj = malloc(class->__size__);
    if (!(obj))
        raise("Out of memory");
    if (!(memcpy(obj, class, class->__size__)))
        raise("Memcpy failed");
    if (obj->__ctor__)
        obj->__ctor__(obj, list);
    return ((Object *)(obj));
}

void delete(Object *obj)
{
    Class *_obj = (Class *)(obj);

    if (obj && _obj->__dtor__)
        _obj->__dtor__(obj);
    free(obj);
}
