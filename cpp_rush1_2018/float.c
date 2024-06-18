/*
** EPITECH PROJECT, 2019
** cpp_rush1_2018
** File description:
** float
*/

#include <string.h>
#include "new.h"
#include "float.h"

#define KEY (10 + 15 + 1)

enum Operations {
    ADD, SUB, MULT, DIV, EQ, SUP, GT, LT
};

typedef struct
{
    Class base;
    float data;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!(this) || !(args))
        raise("Wrong pointer");
    this->data = (float)(va_arg(*args, double));
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static const char *Float_str(FloatClass *this)
{
    static char res[KEY] = { 0 };

    if (!(this))
        raise("Wrong pointer");
    snprintf(res, KEY, "<Float (%f)>", this->data);
    return (strdup(res));
}

static float process_op(FloatClass *this, FloatClass *obj, int op)
{
    switch (op) {
    case (ADD):
        return (this->data + obj->data);
    case (SUB):
        return (this->data - obj->data);
    case (MULT):
        return (this->data * obj->data);
    case (DIV):
        return (obj->data ? this->data / obj->data : 0);
    }
    return (0.0f);
}

static Object *Float_operate(const Object *this, const Object *obj, int op)
{
    FloatClass *_this = (FloatClass *)(this);
    FloatClass *_obj = (FloatClass *)(obj);

    if (!(this) || !(obj))
        raise("Wrong pointer");
    return (new(Float, process_op(_this, _obj, op)));
}

static float process_compare(FloatClass *this, FloatClass *obj, int op)
{
    switch (op) {
    case (EQ):
        return (this->data == obj->data);
    case (GT):
        return (this->data > obj->data);
    case (LT):
        return (this->data < obj->data);
    }
    return (false);
}

static bool Float_compare(const Object *this, const Object *obj, int op)
{
    FloatClass *_this = (FloatClass *)(this);
    FloatClass *_obj = (FloatClass *)(obj);

    if (!(_this) || !(_obj))
        raise("Wrong pointer");
    return (process_compare(_this, _obj, op));
}

static Object *Float_add(const Object *this, const Object *obj)
{
    return (Float_operate(this, obj, ADD));
}

static Object *Float_sub(const Object *this, const Object *obj)
{
    return (Float_operate(this, obj, SUB));
}

static Object *Float_mult(const Object *this, const Object *obj)
{
    return (Float_operate(this, obj, MULT));
}

static Object *Float_div(const Object *this, const Object *obj)
{
    return (Float_operate(this, obj, DIV));
}

static bool Float_eq(const Object *this, const Object *obj)
{
    return (Float_compare(this, obj, EQ));
}

static bool Float_gt(const Object *this, const Object *obj)
{
    return (Float_compare(this, obj, GT));
}

static bool Float_lt(const Object *this, const Object *obj)
{
    return (Float_compare(this, obj, LT));
}

static FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mult,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .data = 0
};

Class *Float = (Class *)&_description;
