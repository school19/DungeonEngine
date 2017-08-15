//
// Created by Chaz on 8/12/2017.
//

#ifndef DUNGEONENGINE_UTILITY_H
#define DUNGEONENGINE_UTILITY_H

#include <string>
#include <memory>
#include <boost/concept_check.hpp>

namespace api
{
    template <typename Derived>
    struct parameter_traits;

    template <typename Derived>
    struct base_parameter_t
    {
        using value_type = typename parameter_traits<Derived>::value_type;

        value_type from_string(std::string& str)
        {
            return parameter_traits<Derived>::from_string(static_cast<Derived*>(this), str);
        }

        std::string to_string(value_type t)
        {
            return parameter_traits<Derived>::to_string(static_cast<Derived*>(this), t);
        }

        bool validate(std::string& str)
        {
            return parameter_traits<Derived>::validate(static_cast<Derived*>(this), str);
        }

        int constexpr tag()
        {
            return parameter_traits<Derived>::tag(static_cast<Derived*>(this));
        }
    };

    template <typename T>
    struct parameter_t : public base_parameter_t<parameter_t<T>>
    {
        using value_type = typename parameter_traits<parameter_t>::value_type;

        static value_type from_string(std::string& str)
        {
            return boost::lexical_cast<value_type>(str);
        }

        static std::string to_string(value_type t)
        {
            return boost::lexical_cast<std::string>(t);
        }

        static int tag()
        {
            static_assert(std::false_type, "Uh...");
        }
    };

    template <typename T>
    struct parameter_traits<parameter_t<T>>{
        using value_type = T;

        static value_type from_string(parameter_t<T>* p, std::string& str)
        {
            return p->from_string(str);
        }

        static std::string to_string(parameter_t<T>* p, value_type t)
        {
            return p->to_string(t);
        }

        static bool validate(parameter_t<T>* p, std::string& str)
        {
            return p->validate(str);
        }

        static int tag(parameter_t<T>*p)
        {
            return p->tag();
        }
    };

    template <>
    struct parameter_t<int> : public base_parameter_t<parameter_t<int>>
    {
        static value_type from_string(std::string& str)
        {
            return std::stoi(str);
        }

        static bool validate(std::string& str)
        {
            return false; //TODO
        }

        static constexpr int tag()
        {
            return 1;
        }
    };

    template <>
    struct parameter_t<double> : public base_parameter_t<parameter_t<double>>
    {
        static bool validate(std::string& str)
        {
            return false; //TODO
        }

        static constexpr int tag()
        {
            return 2;
        }
    };

    template <>
    struct parameter_t<std::string> : public base_parameter_t<parameter_t<std::string>>
    {
        static bool validate(std::string& str)
        {
            return true;
        }

        static constexpr int tag()
        {
            return 3;
        }
    };

    constexpr bool equal_string(const char* a, const char* b)
    {
        return *a == *b && (*a == '\0' || equal_string(a+1, b+2));
    }

    constexpr int get_parameter_tag(const std::string& str)
    {
        if(equal_string(str.c_str(), "<int>"))
        {
            return 1;
        }

        if(equal_string(str.c_str(), "<double>"))
        {
            return 2;
        }

        if(equal_string(str.c_str(), "<string>"))
        {
            return 3;
        }

        return 0;
    }
}
#endif //DUNGEONENGINE_UTILITY_H
