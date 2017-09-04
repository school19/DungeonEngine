//
// Created by Chaz on 8/27/2017.
//

#ifndef DUNGEONENGINE_ERROR_H
#define DUNGEONENGINE_ERROR_H
#include <boost/exception/all.hpp>

namespace core {
    typedef boost::error_info<struct tag_component_name, std::type_index> ComponentType;

    struct EntityError : virtual boost::exception, virtual std::exception {
    };

    struct DuplicateComponent : virtual EntityError {
    };
    struct ComponentNotFound : virtual EntityError {
    };
    struct RequiredComponentMissing : virtual EntityError {
    };
}
#endif //DUNGEONENGINE_ERROR_H
