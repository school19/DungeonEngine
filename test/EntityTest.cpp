//
// Created by Chaz on 8/26/2017.
//

#include <boost/test/unit_test.hpp>
#include <memory>
#include <string>
#include <Entity.h>
#include <EntityComponent.h>

using namespace std::string_literals;

class MockEntityComponent : public EntityComponent
{
public:
    MockEntityComponent(std::string& name): mName(name){}
    ~MockEntityComponent() = default;

    const std::string& getName(){return mName;}
private:
    std::string mName;
};

BOOST_AUTO_TEST_SUITE(EntityTestSuite)

BOOST_AUTO_TEST_CASE(ComponentAdd)
{
    std::shared_ptr<EntityComponent> ptr = std::make_shared<MockEntityComponent>("test_component"s);
    Entity e;
    e.addComponent(ptr);
}

BOOST_AUTO_TEST_SUITE_END()