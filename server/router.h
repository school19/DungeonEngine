//
// Created by Chaz on 8/11/2017.
//

#ifndef DUNGEONENGINE_ROUTER_H
#define DUNGEONENGINE_ROUTER_H

#include <string>
#include <boost/beast/http/message.hpp>
#include <boost/beast/http/string_body.hpp>
#include <utility>
#include <deque>
#include <sstream>
#include <type_traits>
#include "utility.h"

namespace api
{
    namespace detail {

        template <typename Derived>
        class node_base
        {
        public:

            void add_child(std::shared_ptr<node_base> ptr)
            {
                _children.push_back(ptr);
            }

            virtual bool match(std::string& piece) = 0;

            std::shared_ptr<node_base> find_child(std::string piece)
            {
                for (auto& ptr : _children)
                {
                    if(ptr->match(piece))
                    {
                        return ptr;
                    }
                }
                return nullptr;
            }

        private:
            std::vector<std::shared_ptr<node_base>> _children;
        };

        struct const_node : public node_base<const_node>
        {
        public:
            const_node(std::string& val) : _val(val)
            {}

            virtual bool matches(std::string& piece)
            {
                return _val == piece;
            }

        private:
            std::string _val;
        };

        template <typename T>
        class variable_node : public node_base<variable_node<T>>
        {
        public:
            using param_type = api::parameter_t<T>;

            virtual bool matches(std::string& piece)
            {
                return _p.validate(piece);
            }

        private:
            param_type _p;
        };

        class trie {
        public:
            trie(): _root(""s){}

            template <typename ...Args>
            constexpr void add(const std::string& path, unsigned int route_index)
            {
                std::istringstream tmp_stream(path);
                std::deque<std::string> parts;
                std::string tmp;

                while(std::getline(tmp_stream, tmp, '/'))
                {
                    parts.push_back(tmp);
                }

                add_internal<Args...>(&_root, parts, route_index);
            }

        private:
            template <>
            constexpr void add_internal(node_base* parent, std::deque<std::string>& parts, unsigned int route_index)
            {

            }

            template <typename T>
            constexpr void add_internal(node_base* parent, std::deque<std::string>& parts, unsigned int route_index)
            {
                if(parts.size() == 0)
                {
                    static_assert(std::false_type, "No more parts but still have parameters to check!");
                }
            }

            template <typename T, typename ...Args>
            constexpr void add_internal(node_base* parent, std::deque<std::string>& parts, unsigned int route_index)
            {
                if(parts.size() == 0)
                {
                    static_assert(std::false_type, "No more parts but still have parameters to check!");
                }

                std::string piece = parts.front();
                parts.pop_front();

                //node* new_node;
                if(piece[0] == '<')
                {
                    //create a 'variable' node and use the Args type to instantiate a parameter_t structure and store it
                    static_assert(get_parameter_tag(piece) == )
                    std::shared_ptr<variable_node<T>> node = std::make_shared<variable_node<T>>();
                    parent->add_child(node);
                    add_internal<Args...>(node.get(), parts, route_index);
                }
                else
                {
                    //store the string as a constant node
                    std::shared_ptr<const_node> node = std::make_shared<const_node>(piece);
                    parent->add_child(node);
                    add_internal<T, Args...>(node.get(), parts, route_index);
                }
            }

            const_node _root;
        };
    }

    class base_route{
    public:
        base_route(std::string path): _path(std::move(path))
        {}

    private:
        std::string _path;
    };

    template <typename ...Args>
    class route : public base_route{
    public:
        using handler_args = std::tuple<Args...>;

        route(std::string path): base_route(path) {}
    };

    class router{
    public:
        template <typename ...Args>
        route<Args...>& add_route(std::string path)
        {
            using RouteT = typename route<Args...>
            std::unique_ptr<RouteT> r = std::make_unique<RouteT>(path);

            //TODO add to internal trie structure
            _routes.push_back(std::move(r));

            return *r;
        }

    private:
        std::vector<std::unique_ptr<base_route>> _routes;
        detail::trie _trie;
    };
}

#endif //DUNGEONENGINE_ROUTER_H
