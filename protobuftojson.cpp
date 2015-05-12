//
/// \file protobuftojson.cpp
/// \author Lumate
/// \brief Implementation of functions for serializing protobufs to json strings
//

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
#include <string>

void serializeToString(google::protobuf::message::Message object, std::map<std::string, std::string> FIELDS, std::string &output)
{
    std::vector<const google::protobuf::FieldDescriptor *> fields;
    object.GetReflection()->ListFields(object, &fields);
    std::string fname;
    rapidjson::Document newdoc;
    for (auto i: fields)
    {
        fname = i->name();
        if (FIELDS.count(i->name()))
            fname = FIELDS.at(i->name());

        switch(i->cpp_type())
        {
            case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
                newdoc.AddMember(fname, object.GetReflection()->GetInt32(object, i), newdoc.GetAllocator());
                break;
            case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
                newdoc.AddMember(fname, object.GetReflection()->GetInt64(object, i), newdoc.GetAllocator());
                break;
            case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
                newdoc.AddMember(fname, object.GetReflection()->GetString(object, i), newdoc.GetAllocator());
                break;
            case google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
                newdoc.AddMember(fname, object.GetReflection()->GetDouble(object, i), newdoc.GetAllocator());
                break;
            case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
                newdoc.AddMember(fname, static_cast<double>(object.GetReflection()->GetFloat(object, i), newdoc.GetAllocator());
                break;
            case google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
                newdoc.AddMember(fname, object.GetReflection()->GetBool(object, i), newdoc.GetAllocator());
                break;
        }
    }
}

std::string serializeAsString(google::protobuf::message::Message object, std::map<std::string, std::string> FIELDS)
{
    std::string output;
    serializeToString(object, FIELDS, output);
    return output;
}
