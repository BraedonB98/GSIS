cmake_minimum_required(VERSION 3.16)
project(MainCode)

set(CMAKE_CXX_STANDARD 14)



add_executable(MainCode main.cpp ui.cpp ui.h satData.cpp satData.h Settings.cpp Settings.h )

add_executable(SatTest satDataTest.cpp ui.cpp ui.h satData.cpp satData.h Settings.cpp Settings.h )

add_executable(SettingsTest settingsTestFile.cpp ui.cpp ui.h satData.cpp satData.h Settings.cpp Settings.h settingsTestFile.cpp)



