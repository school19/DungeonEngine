#pragma once
#include <boost/exception/all.hpp>
#include <exception>

struct file_error : virtual std::exception, virtual boost::exception {};
struct file_not_found_error : virtual file_error {};
struct incorrect_file_type_error : virtual file_error {};

struct script_error : virtual std::exception, virtual boost::exception {};
struct script_load_error : virtual script_error {};
struct incorrect_return_type : virtual std::exception, virtual boost::exception {};

typedef boost::error_info<struct tag_lua_msg, std::string> errinfo_lua_message;

std::string luaTypeName(int type);