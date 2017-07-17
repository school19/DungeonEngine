cmake_minimum_required(VERSION 3.4.1)

add_library(engine
			STATIC
		ErrorListener.h
			ErrorListener.cpp
		OStreamErrorListener.cpp OStreamErrorListener.h Race.cpp Race.h Character.cpp Character.h CharacterClass.cpp CharacterClass.h CharacterClassInstance.cpp CharacterClassInstance.h RaceInstance.cpp RaceInstance.h CharacterState.cpp CharacterState.h TokenStream.h Token.cpp Token.h TokenStream.cpp TokenStreamReader.h TokenStreamWriter.h RaceProxy.cpp RaceProxy.h CharacterClassProxy.cpp CharacterClassProxy.h JsonTokenStreamReader.cpp JsonTokenStreamReader.h TokenStreamWriter.cpp Event.cpp Event.h Inventory.cpp Inventory.h ItemEntry.cpp ItemEntry.h Item.cpp Item.h)
			
target_include_directories(engine PUBLIC ${RAPIDJSON_INCLUDE_DIRS})

set_target_properties(engine PROPERTIES LINKER_LANGUAGE CXX)