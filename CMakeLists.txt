##
## QtEmu - A front-end for qemu emulator
##
## Copyright (C) 2006-2008 Urs Wolfer <uwolfer @ fwo.ch> and Ben Klopfenstein <benklop gmail com>
## Copyright (C) 2017-2025 Sergio Carlavilla <sergio.carlavilla91 @ gmail.com>
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU Library General Public License
## along with this library; see the file COPYING.LIB.  If not, write to
## the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
## Boston, MA 02110-1301, USA.
##
##-------------------------------------------------
##
## Project created by the awesome QtCreator
##
##-------------------------------------------------
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(qtemu LANGUAGES CXX)

message("Generating Makefile for QtEmu... $$escape_expand(\\n)")

# Compilation options
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt configuration
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

if (UNIX)
    include(GNUInstallDirs)
endif()

# CMake configuration
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(SOURCES
    src/main.cpp
    src/components/customfilter.cpp
    src/mainwindow.cpp
    src/helpwidget.cpp
    src/aboutwidget.cpp
    src/configwindow.cpp
    src/machinewizard.cpp
    src/machine.cpp
    src/newmachine/machinepage.cpp
    src/utils/systemutils.cpp
    src/newmachine/generalpage.cpp
    src/newmachine/hardwarepage.cpp
    src/newmachine/acceleratorpage.cpp
    src/newmachine/memorypage.cpp
    src/newmachine/diskpage.cpp
    src/newmachine/conclusionpage.cpp
    src/machineconfig/machineconfigwindow.cpp
    src/utils/logger.cpp
    src/machineutils.cpp
    src/machineconfig/machineconfiggeneral.cpp
    src/machineconfig/machineconfighardware.cpp
    src/machineconfig/machineconfigboot.cpp
    src/machineconfig/machineconfigmedia.cpp
    src/machineconfig/machineconfignetwork.cpp
    src/machineconfig/machineconfigaudio.cpp
    src/machineconfig/machineconfigaccel.cpp
    src/utils/newdiskwizard.cpp
    src/qemu.cpp
    src/machineconfig/machineconfiggeneraltabs.cpp
    src/machineconfig/machineconfighardwaretabs.cpp
    src/utils/firstrunwizard.cpp
    src/boot.cpp
    src/media.cpp
    src/export-import/export.cpp
    src/export-import/exportgeneralpage.cpp
    src/export-import/exportmediapage.cpp
    src/export-import/import.cpp
    src/export-import/importgeneralpage.cpp
    src/export-import/importdestinationpage.cpp
    src/export-import/exportdetailspage.cpp
    src/export-import/importdetailspage.cpp
    src/export-import/importmediapage.cpp
)

set(HEADERS
    src/mainwindow.h
    src/components/customfilter.h
    src/helpwidget.h
    src/aboutwidget.h
    src/configwindow.h
    src/machinewizard.h
    src/machine.h
    src/utils/systemutils.h
    src/newmachine/generalpage.h
    src/newmachine/machinepage.h
    src/newmachine/hardwarepage.h
    src/newmachine/acceleratorpage.h
    src/newmachine/memorypage.h
    src/newmachine/diskpage.h
    src/newmachine/conclusionpage.h
    src/machineconfig/machineconfigwindow.h
    src/utils/logger.h
    src/machineutils.h
    src/machineconfig/machineconfiggeneral.h
    src/machineconfig/machineconfighardware.h
    src/machineconfig/machineconfigboot.h
    src/machineconfig/machineconfigmedia.h
    src/machineconfig/machineconfignetwork.h
    src/machineconfig/machineconfigaudio.h
    src/machineconfig/machineconfigaccel.h
    src/utils/newdiskwizard.h
    src/qemu.h
    src/machineconfig/machineconfiggeneraltabs.h
    src/machineconfig/machineconfighardwaretabs.h
    src/utils/firstrunwizard.h
    src/boot.h
    src/media.h
    src/export-import/export.h
    src/export-import/exportgeneralpage.h
    src/export-import/exportmediapage.h
    src/export-import/import.h
    src/export-import/importgeneralpage.h
    src/export-import/importdestinationpage.h
    src/export-import/exportdetailspage.h
    src/export-import/importdetailspage.h
    src/export-import/importmediapage.h
)

set(RESOURCES qtemu.qrc)

add_executable(qtemu
    ${HEADERS}
    ${SOURCES}
    ${RESOURCES}
)

target_link_libraries(qtemu
    Qt6::Core
    Qt6::Gui
    Qt6::Network
    Qt6::Widgets
)

set(OTHER_FILES
    CHANGELOG
    LICENSE
    README
    translations
)

if(UNIX)
    set(OTHER_FILES
    ${OTHER_FILES}
    qtemu.desktop
)
endif()

if(NOT source_date_epoch_ISEMPTY)
    target_compile_definitions(qtemu PRIVATE
        REPRODUCIBLEBUILD
    )
endif()

install(TARGETS qtemu
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
