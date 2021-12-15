set(ACESENGINE_HEADERS
	AcesWindow.h
	Drawable.h
	Draggable.h
	Inputable.h
	Card.h
	Player.h
	SoundPlayer.h
	TextWriter.h
 )

set(ACESENGINE_SOURCES
	AcesWindow.cpp
	Drawable.cpp
	Draggable.cpp
	Inputable.cpp
	Card.cpp
	Player.cpp
	SoundPlayer.cpp
	TextWriter.cpp
 )

add_library(AcesEngine STATIC ${ACESENGINE_SOURCES} ${ACESENGINE_HEADERS} acesengine.h root_directory.h)
if (MSVC)
    target_compile_options(AcesEngine PUBLIC /wd5033)
endif(MSVC)
target_include_directories(AcesEngine PRIVATE ${THIRD_PARTY_INCLUDE_DIRECTORIES} ACESENGINE_INCLUDE_DIRECTORY)
target_link_libraries(AcesEngine PRIVATE ${THIRD_PARTY_LIBRARIES})
set_property(TARGET AcesEngine PROPERTY CXX_STANDARD 20)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ACESENGINE_SOURCES} ${ACESENGINE_HEADERS})