cmake_minimum_required (VERSION 3.11)

include(FetchContent)

# dependencies
# FTXUI
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
)
FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# SQLite
set(SQLite_URL "https://www.sqlite.org/2023/sqlite-amalgamation-3430100.zip")
FetchContent_Declare(
  SQLite
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  URL ${SQLite_URL}
)
FetchContent_GetProperties(SQLite)
if(NOT SQLite_POPULATED)
  FetchContent_Populate(SQLite)
endif()

# project definition
project(orion_airlines
  LANGUAGES CXX
  VERSION 1.0.0
)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.hpp")
add_executable(orion_airlines ${SOURCES} ${HEADERS})
target_compile_features(orion_airlines PRIVATE cxx_std_20)
target_include_directories(orion_airlines PRIVATE src)

# SQLite
target_sources(orion_airlines PRIVATE ${CMAKE_BINARY_DIR}/_deps/sqlite-src/sqlite3.h)
target_include_directories(orion_airlines PRIVATE ${CMAKE_BINARY_DIR}/_deps/sqlite-src)

target_link_libraries(orion_airlines
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
  PRIVATE sqlite3
)
