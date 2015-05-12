//
/// \file protobuftojson.h
/// \author Lumate
/// \brief Functions for serializing protobufs to json strings
//

// write json string to provided output string
void serializeToString(google::protobuf::message::Message object, std::map<std::string, std::string> FIELDS, std::string &output)

// return json string of protobuf
std::string serializeAsString(google::protobuf::message::Message object, std::map<std::string, std::string> FIELDS)
