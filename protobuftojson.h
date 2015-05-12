//
/// \file protobuftojson.h
/// \author Lumate
/// \brief Functions for serializing protobufs to json strings
//

#ifndef PROTOBUFTOSJON
#define PROTOBUFTOSJON

//
/// \brief write json string to provided output string
//
void serializeToString(google::protobuf::message::Message object, std::map<std::string, std::string> FIELDS, std::string &output);

//
/// \brief return json string of protobuf
//
std::string serializeAsString(google::protobuf::message::Message object, std::map<std::string, std::string> FIELDS);

#endif // PROTOBUFTOSJON\
