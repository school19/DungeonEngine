//
// Created by Chaz on 8/27/2017.
//

#ifndef DUNGEONENGINE_ERROR_H
#define DUNGEONENGINE_ERROR_H
#include <boost/exception/all.hpp>

typedef boost::error_info<struct tag_component_name, std::string> ComponentName;

struct EntityError : virtual boost::exception, virtual std::exception{};

struct DuplicateComponent : virtual EntityError{};
struct ComponentNotFound : virtual EntityError{};

#endif //DUNGEONENGINE_ERROR_H
