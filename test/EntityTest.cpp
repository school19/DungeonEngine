//
// Created by Chaz on 8/26/2017.
//

#include <boost/test/unit_test.hpp>
#include <memory>
#include <string>
#include <Entity.h>
#include <EntityComponent.h>
#include <Logger.h>
using namespace std::string_literals;
using core::entity::EntityComponent;
using core::entity::Entity;
using core::DuplicateComponent;
using core::ComponentNotFound;

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

        BOOST_CHECK_NO_THROW(e.addComponent(ptr));

        BOOST_CHECK_EQUAL(e.get<MockEntityComponent>()->getName(), "test_component"s);

        std::shared_ptr<EntityComponent> duplicate = std::make_shared<MockEntityComponent>("duplicate"s);

        BOOST_CHECK_THROW(e.addComponent(duplicate), DuplicateComponent);
    }

    BOOST_AUTO_TEST_CASE(EmptyEntity)
    {
        Entity e;

        BOOST_CHECK_THROW(e.get<MockEntityComponent>(), ComponentNotFound);

        std::shared_ptr<EntityComponent> ptr = std::make_shared<MockEntityComponent>("test_component"s);
        BOOST_CHECK_THROW(e.removeComponent(ptr), ComponentNotFound);
    }

BOOST_AUTO_TEST_SUITE_END()