cmake_minimum_required(VERSION 3.4.1)

add_library(core
			STATIC
		Spell.cpp Spell.h Entity.cpp Entity.h EntityComponent.h HealthComponent.cpp HealthComponent.h EntityOperation.h Logger.h Formatter.h Error.h DamageApplicator.cpp DamageApplicator.h Constants.h EventManager.cpp EventManager.h DungeonEngine.cpp DungeonEngine.h Map.h Event.h EventManager.cpp EventManager.h Context.h Context.cpp MapView.cpp MapView.h Utility.h)
			
target_include_directories(core PUBLIC ${RAPIDJSON_INCLUDE_DIRS})

set_target_properties(core PROPERTIES LINKER_LANGUAGE CXX)