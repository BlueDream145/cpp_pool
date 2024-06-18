/*
** EPITECH PROJECT, 2019
** cpp_rush1_2018
** File description:
** int
*/

#include <string.h>
#include "new.h"
#include "int.h"

#define KEY (10 + 8 + 1)

enum Operations {
    ADD, SUB, MULT, DIV, EQ, SUP, GT, LT
};

typedef struct
{
    Class base;
    int data;
} IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (!(this) || !(args))
        raise("Wrong pointer");
    this->data = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

static const char *Int_str(IntClass *this)
{
    static char res[KEY] = { 0 };

    if (!(this))
        raise("Wrong pointer");
    snprintf(res, KEY, "<Int (%d)>", this->data);
    return (strdup(res));
}

static int process_op(IntClass *this, IntClass *obj, int op)
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
    return (0);
}

static Object *Int_operate(const Object *this, const Object *obj, int op)
{
    IntClass *_this = (IntClass *)(this);
    IntClass *_obj = (IntClass *)(obj);

    if (!(this) || !(obj))
        return (NULL);
    return (new(Int, process_op(_this, _obj, op)));
}

static int process_compare(IntClass *this, IntClass *obj, int op)
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

static bool Int_compare(const Object *this, const Object *obj, int op)
{
    IntClass *_this = (IntClass *)(this);
    IntClass *_obj = (IntClass *)(obj);

    if (!(_this) || !(_obj))
        return (false);
    return (process_compare(_this, _obj, op));
}

static Object *Int_add(const Object *this, const Object *obj)
{
    return (Int_operate(this, obj, ADD));
}

static Object *Int_sub(const Object *this, const Object *obj)
{
    return (Int_operate(this, obj, SUB));
}

static Object *Int_mult(const Object *this, const Object *obj)
{
    return (Int_operate(this, obj, MULT));
}

static Object *Int_div(const Object *this, const Object *obj)
{
    return (Int_operate(this, obj, DIV));
}

static bool Int_eq(const Object *this, const Object *obj)
{
    return (Int_compare(this, obj, EQ));
}

static bool Int_gt(const Object *this, const Object *obj)
{
    return (Int_compare(this, obj, GT));
}

static bool Int_lt(const Object *this, const Object *obj)
{
    return (Int_compare(this, obj, LT));
}

static IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mult,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .data = 0
};

Class *Int = (Class *)&_description;
