cmake_minimum_required(VERSION 3.4.1)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED filesystem)

add_library(engine
			SHARED
			Error.cpp
			Error.h
			ErrorListener.h
			ErrorListener.cpp
			DungeonEngine.cpp
			DungeonEngine.h
			Ruleset.cpp
			Ruleset.h OStreamErrorListener.cpp OStreamErrorListener.h UiProvider.h UiProvider.cpp UiProviderImpl.h Label.cpp Label.h LabelImpl.h UiProviderImplFactory.h Window.cpp Window.h WindowImpl.h)
			
include_directories(engine ${Boost_INCLUDE_DIRS} ../lua)
link_directories(${Boost_LIBRARY_DIR})

target_link_libraries(engine ${Boost_LIBRARIES} lualib)
set_target_properties(engine PROPERTIES LINKER_LANGUAGE CXX)