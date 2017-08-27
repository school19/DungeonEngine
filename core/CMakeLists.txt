cmake_minimum_required(VERSION 3.4.1)

add_library(core
			STATIC
		Spell.cpp Spell.h Entity.cpp Entity.h EntityComponent.h HealthComponent.cpp HealthComponent.h EntityOperation.h ClassComponent.cpp ClassComponent.h MultiClassComponent.cpp MultiClassComponent.h RaceComponent.cpp RaceComponent.h)
			
target_include_directories(core PUBLIC ${RAPIDJSON_INCLUDE_DIRS})

set_target_properties(core PROPERTIES LINKER_LANGUAGE CXX)