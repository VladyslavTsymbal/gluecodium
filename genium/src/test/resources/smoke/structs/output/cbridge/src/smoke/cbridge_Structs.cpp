//
//
// Automatically generated. Do not modify. Your changes will be lost.
#include "cbridge/include/smoke/cbridge_Structs.h"
#include "cbridge_internal/include/BaseHandleImpl.h"
#include "foo/Bar.h"
#include "foo/Bazz.h"
#include "smoke/Structs.h"
#include <memory>
#include <new>
#include <string>
#include <vector>
void smoke_Structs_release_handle(_baseRef handle) {
    delete get_pointer<std::shared_ptr<::smoke::Structs>>(handle);
}
_baseRef smoke_Structs_copy_handle(_baseRef handle) {
    return handle
        ? reinterpret_cast<_baseRef>(checked_pointer_copy(*get_pointer<std::shared_ptr<::smoke::Structs>>(handle)))
        : 0;
}
_baseRef smoke_Structs_Point_create_handle(double x, double y) {
    ::smoke::Structs::Point* _struct = new ::smoke::Structs::Point();
    _struct->x = x;
    _struct->y = y;
    return reinterpret_cast<_baseRef>(_struct);
}
void smoke_Structs_Point_release_handle(_baseRef handle) {
    delete get_pointer<::smoke::Structs::Point>(handle);
}
double smoke_Structs_Point_x_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::Point>(handle);
return struct_pointer->x;
}
double smoke_Structs_Point_y_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::Point>(handle);
return struct_pointer->y;
}
_baseRef smoke_Structs_Color_create_handle(uint8_t red, uint8_t green, uint8_t blue) {
    ::smoke::Structs::Color* _struct = new ::smoke::Structs::Color();
    _struct->red = red;
    _struct->green = green;
    _struct->blue = blue;
    return reinterpret_cast<_baseRef>(_struct);
}
void smoke_Structs_Color_release_handle(_baseRef handle) {
    delete get_pointer<::smoke::Structs::Color>(handle);
}
uint8_t smoke_Structs_Color_red_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::Color>(handle);
return struct_pointer->red;
}
uint8_t smoke_Structs_Color_green_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::Color>(handle);
return struct_pointer->green;
}
uint8_t smoke_Structs_Color_blue_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::Color>(handle);
return struct_pointer->blue;
}
_baseRef smoke_Structs_Line_create_handle(_baseRef a, _baseRef b) {
    ::smoke::Structs::Line* _struct = new ::smoke::Structs::Line();
    _struct->a = Conversion<::smoke::Structs::Point>::toCpp(a);
    _struct->b = Conversion<::smoke::Structs::Point>::toCpp(b);
    return reinterpret_cast<_baseRef>(_struct);
}
void smoke_Structs_Line_release_handle(_baseRef handle) {
    delete get_pointer<::smoke::Structs::Line>(handle);
}
_baseRef smoke_Structs_Line_a_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::Line>(handle);
return Conversion<::smoke::Structs::Point>::toBaseRef(struct_pointer->a);
}
_baseRef smoke_Structs_Line_b_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::Line>(handle);
return Conversion<::smoke::Structs::Point>::toBaseRef(struct_pointer->b);
}
_baseRef smoke_Structs_ColoredLine_create_handle(_baseRef line, _baseRef color) {
    ::smoke::Structs::ColoredLine* _struct = new ::smoke::Structs::ColoredLine();
    _struct->line = Conversion<::smoke::Structs::Line>::toCpp(line);
    _struct->color = Conversion<::smoke::Structs::Color>::toCpp(color);
    return reinterpret_cast<_baseRef>(_struct);
}
void smoke_Structs_ColoredLine_release_handle(_baseRef handle) {
    delete get_pointer<::smoke::Structs::ColoredLine>(handle);
}
_baseRef smoke_Structs_ColoredLine_line_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::ColoredLine>(handle);
return Conversion<::smoke::Structs::Line>::toBaseRef(struct_pointer->line);
}
_baseRef smoke_Structs_ColoredLine_color_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::ColoredLine>(handle);
return Conversion<::smoke::Structs::Color>::toBaseRef(struct_pointer->color);
}
_baseRef smoke_Structs_AllTypesStruct_create_handle(int8_t int8Field, uint8_t uint8Field, int16_t int16Field, uint16_t uint16Field, int32_t int32Field, uint32_t uint32Field, int64_t int64Field, uint64_t uint64Field, float floatField, double doubleField, _baseRef stringField, bool booleanField, _baseRef bytesField, _baseRef pointField) {
    auto _int8Field = int8Field;
    auto _uint8Field = uint8Field;
    auto _int16Field = int16Field;
    auto _uint16Field = uint16Field;
    auto _int32Field = int32Field;
    auto _uint32Field = uint32Field;
    auto _int64Field = int64Field;
    auto _uint64Field = uint64Field;
    auto _floatField = floatField;
    auto _doubleField = doubleField;
    auto _stringField = Conversion<std::string>::toCpp(stringField);
    auto _booleanField = booleanField;
    auto _bytesField = Conversion<::std::shared_ptr< ::std::vector< uint8_t > >>::toCpp(bytesField);
    auto _pointField = Conversion<::smoke::Structs::Point>::toCpp(pointField);
    ::smoke::Structs::AllTypesStruct* _struct = new ::smoke::Structs::AllTypesStruct(_int8Field, _uint8Field, _int16Field, _uint16Field, _int32Field, _uint32Field, _int64Field, _uint64Field, _floatField, _doubleField, _stringField, _booleanField, _bytesField, _pointField);
    return reinterpret_cast<_baseRef>(_struct);
}
void smoke_Structs_AllTypesStruct_release_handle(_baseRef handle) {
    delete get_pointer<::smoke::Structs::AllTypesStruct>(handle);
}
int8_t smoke_Structs_AllTypesStruct_int8Field_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return struct_pointer->int8_field;
}
uint8_t smoke_Structs_AllTypesStruct_uint8Field_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return struct_pointer->uint8_field;
}
int16_t smoke_Structs_AllTypesStruct_int16Field_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return struct_pointer->int16_field;
}
uint16_t smoke_Structs_AllTypesStruct_uint16Field_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return struct_pointer->uint16_field;
}
int32_t smoke_Structs_AllTypesStruct_int32Field_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return struct_pointer->int32_field;
}
uint32_t smoke_Structs_AllTypesStruct_uint32Field_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return struct_pointer->uint32_field;
}
int64_t smoke_Structs_AllTypesStruct_int64Field_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return struct_pointer->int64_field;
}
uint64_t smoke_Structs_AllTypesStruct_uint64Field_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return struct_pointer->uint64_field;
}
float smoke_Structs_AllTypesStruct_floatField_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return struct_pointer->float_field;
}
double smoke_Structs_AllTypesStruct_doubleField_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return struct_pointer->double_field;
}
_baseRef smoke_Structs_AllTypesStruct_stringField_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return Conversion<std::string>::toBaseRef(struct_pointer->string_field);
}
bool smoke_Structs_AllTypesStruct_booleanField_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return struct_pointer->boolean_field;
}
_baseRef smoke_Structs_AllTypesStruct_bytesField_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return Conversion<::std::shared_ptr< ::std::vector< uint8_t > >>::toBaseRef(struct_pointer->bytes_field);
}
_baseRef smoke_Structs_AllTypesStruct_pointField_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::AllTypesStruct>(handle);
return Conversion<::smoke::Structs::Point>::toBaseRef(struct_pointer->point_field);
}
_baseRef smoke_Structs_ExternalStruct_create_handle(_baseRef stringField, _baseRef externalStringField, _baseRef externalArrayField, _baseRef externalStructField) {
    ::smoke::Structs::ExternalStruct* _struct = new ::smoke::Structs::ExternalStruct();
    _struct->stringField = Conversion<std::string>::toCpp(stringField);
    _struct->set_some_string(Conversion<std::string>::toCpp(externalStringField));
    _struct->set_some_array(Conversion<std::vector<int8_t>>::toCpp(externalArrayField));
    _struct->set_some_struct(Conversion<::fire::SomeVeryExternalStruct>::toCpp(externalStructField));
    return reinterpret_cast<_baseRef>(_struct);
}
void smoke_Structs_ExternalStruct_release_handle(_baseRef handle) {
    delete get_pointer<::smoke::Structs::ExternalStruct>(handle);
}
_baseRef smoke_Structs_ExternalStruct_stringField_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::ExternalStruct>(handle);
return Conversion<std::string>::toBaseRef(struct_pointer->stringField);
}
_baseRef smoke_Structs_ExternalStruct_externalStringField_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::ExternalStruct>(handle);
return Conversion<std::string>::toBaseRef(struct_pointer->get_some_string());
}
_baseRef smoke_Structs_ExternalStruct_externalArrayField_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::ExternalStruct>(handle);
return Conversion<std::vector<int8_t>>::toBaseRef(struct_pointer->get_some_array());
}
_baseRef smoke_Structs_ExternalStruct_externalStructField_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::ExternalStruct>(handle);
return Conversion<::fire::SomeVeryExternalStruct>::toBaseRef(struct_pointer->get_some_struct());
}
_baseRef smoke_Structs_AnotherExternalStruct_create_handle(int8_t intField) {
    ::fire::SomeVeryExternalStruct* _struct = new ::fire::SomeVeryExternalStruct();
    _struct->intField = intField;
    return reinterpret_cast<_baseRef>(_struct);
}
void smoke_Structs_AnotherExternalStruct_release_handle(_baseRef handle) {
    delete get_pointer<::fire::SomeVeryExternalStruct>(handle);
}
int8_t smoke_Structs_AnotherExternalStruct_intField_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::fire::SomeVeryExternalStruct>(handle);
return struct_pointer->intField;
}
_baseRef smoke_Structs_YetAnotherExternalStruct_create_handle(_baseRef stringField) {
    ::smoke::Structs::Yet_Another_External_Struct* _struct = new ::smoke::Structs::Yet_Another_External_Struct();
    _struct->string_Field = Conversion<std::string>::toCpp(stringField);
    return reinterpret_cast<_baseRef>(_struct);
}
void smoke_Structs_YetAnotherExternalStruct_release_handle(_baseRef handle) {
    delete get_pointer<::smoke::Structs::Yet_Another_External_Struct>(handle);
}
_baseRef smoke_Structs_YetAnotherExternalStruct_stringField_get(_baseRef handle) {
    auto struct_pointer = get_pointer<::smoke::Structs::Yet_Another_External_Struct>(handle);
return Conversion<std::string>::toBaseRef(struct_pointer->string_Field);
}
_baseRef smoke_Structs_createPoint(double x, double y) {
    return Conversion<::smoke::Structs::Point>::toBaseRef(::smoke::Structs::create_point(x, y))
;
}
_baseRef smoke_Structs_swapPointCoordinates(_baseRef input) {
    return Conversion<::smoke::Structs::Point>::toBaseRef(::smoke::Structs::swap_point_coordinates(Conversion<::smoke::Structs::Point>::toCpp(input)))
;
}
_baseRef smoke_Structs_createLine(_baseRef pointA, _baseRef pointB) {
    return Conversion<::smoke::Structs::Line>::toBaseRef(::smoke::Structs::create_line(Conversion<::smoke::Structs::Point>::toCpp(pointA), Conversion<::smoke::Structs::Point>::toCpp(pointB)))
;
}
_baseRef smoke_Structs_createColoredLine(_baseRef line, _baseRef color) {
    return Conversion<::smoke::Structs::ColoredLine>::toBaseRef(::smoke::Structs::create_colored_line(Conversion<::smoke::Structs::Line>::toCpp(line), Conversion<::smoke::Structs::Color>::toCpp(color)))
;
}
_baseRef smoke_Structs_returnColoredLine(_baseRef input) {
    return Conversion<::smoke::Structs::ColoredLine>::toBaseRef(::smoke::Structs::return_colored_line(Conversion<::smoke::Structs::ColoredLine>::toCpp(input)))
;
}
_baseRef smoke_Structs_returnAllTypesStruct(_baseRef input) {
    return Conversion<::smoke::Structs::AllTypesStruct>::toBaseRef(::smoke::Structs::return_all_types_struct(Conversion<::smoke::Structs::AllTypesStruct>::toCpp(input)))
;
}
_baseRef smoke_Structs_modifyAllTypesStruct(_baseRef input) {
    return Conversion<::smoke::Structs::AllTypesStruct>::toBaseRef(::smoke::Structs::modify_all_types_struct(Conversion<::smoke::Structs::AllTypesStruct>::toCpp(input)))
;
}
_baseRef smoke_Structs_getExternalStruct() {
    return Conversion<::smoke::Structs::ExternalStruct>::toBaseRef(::smoke::Structs::get_external_struct())
;
}
_baseRef smoke_Structs_getAnotherExternalStruct() {
    return Conversion<::fire::SomeVeryExternalStruct>::toBaseRef(::smoke::Structs::get_another_external_struct())
;
}
_baseRef smoke_Structs_getYetAnotherExternalStruct() {
    return Conversion<::smoke::Structs::Yet_Another_External_Struct>::toBaseRef(::smoke::Structs::get_yet_another_external_struct())
;
}