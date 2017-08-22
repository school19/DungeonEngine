cmake_minimum_required(VERSION 3.4.1)

add_library(core
			STATIC
		PlayerCharacter.cpp PlayerCharacter.h Spell.cpp Spell.h)
			
target_include_directories(core PUBLIC ${RAPIDJSON_INCLUDE_DIRS})

set_target_properties(core PROPERTIES LINKER_LANGUAGE CXX)