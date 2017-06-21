cmake_minimum_required(VERSION 3.4.1)

find_package(Boost REQUIRED 1.64.0 COMPONENTS exception)

add_library(engine
			SHARED
			DungeonEngine
			Ruleset)
			
include_directories(engine ${Boost_INCLUDE_DIRS} ../lua)
target_link_libraries(engine ${Boost_LIBRARIES} lualib)