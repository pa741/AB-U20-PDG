cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)


project(AB-U20-PDG CXX)

################################################################################
# Set target arch type if empty. Visual studio solution generator provides it.
################################################################################
if(NOT CMAKE_VS_PLATFORM_NAME)
    set(CMAKE_VS_PLATFORM_NAME "x64")
endif()
message("${CMAKE_VS_PLATFORM_NAME} architecture in use")

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86"))
    message(FATAL_ERROR "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Global configuration types
################################################################################
set(CMAKE_CONFIGURATION_TYPES
    "Debug"
    "Release"
)

################################################################################
# Global compiler options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_CXX_FLAGS "")
    set(CMAKE_CXX_FLAGS_DEBUG "")
    set(CMAKE_CXX_FLAGS_RELEASE "")
endif()

################################################################################
# Global linker options
################################################################################
if(MSVC)
    # remove default flags provided with CMake for MSVC
    set(CMAKE_EXE_LINKER_FLAGS "")
    set(CMAKE_MODULE_LINKER_FLAGS "")
    set(CMAKE_SHARED_LINKER_FLAGS "")
    set(CMAKE_STATIC_LINKER_FLAGS "")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_DEBUG "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS}")
    set(CMAKE_MODULE_LINKER_FLAGS_RELEASE "${CMAKE_MODULE_LINKER_FLAGS}")
    set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS}")
    set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "${CMAKE_STATIC_LINKER_FLAGS}")
endif()

################################################################################
# Nuget packages function stub.
################################################################################
function(use_package TARGET PACKAGE VERSION)
    message(WARNING "No implementation of use_package. Create yours. "
                    "Package \"${PACKAGE}\" with version \"${VERSION}\" "
                    "for target \"${TARGET}\" is ignored!")
endfunction()

################################################################################
# Common utils
################################################################################
include(CMake/Utils.cmake)

################################################################################
# Additional Global Settings(add specific info there)
################################################################################
include(CMake/GlobalSettingsInclude.cmake OPTIONAL)

################################################################################
# Use solution folders feature
################################################################################
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# Sub-projects
################################################################################



set(PROJECT_NAME AB-U20-PDG)

################################################################################
# Source groups
################################################################################
set(Archivos_de_encabezado
    "AB-U20-PDG.h"
    "Filtro.h"
    "FakeData.h"
    "json.hpp"
)
source_group("Archivos de encabezado" FILES ${Archivos_de_encabezado})

set(Archivos_de_encabezado__Abstract
    "AbsOrdernable.h"
    "AbsPersona.h"
    "AbsSearchable.h"
    "IDataProvider.h"
    "IRecord.h"
    ""
)
source_group("Archivos de encabezado\\Abstract" FILES ${Archivos_de_encabezado__Abstract})

set(Archivos_de_encabezado__CLI
    "CLI.h"
)
source_group("Archivos de encabezado\\CLI" FILES ${Archivos_de_encabezado__CLI})

set(Archivos_de_encabezado__Data
    "Cita.h"
    "Medico.h"
    "Paciente.h"
)
source_group("Archivos de encabezado\\Data" FILES ${Archivos_de_encabezado__Data})

set(Archivos_de_encabezado__DataProviders
    "FileProvider.h"
)
source_group("Archivos de encabezado\\DataProviders" FILES ${Archivos_de_encabezado__DataProviders})

set(Archivos_de_encabezado__Managers
    "MedicoManager.h"
    "PacienteManager.h"
    "CitaManager.h"
)
source_group("Archivos de encabezado\\Managers" FILES ${Archivos_de_encabezado__Managers})

set(Archivos_de_origen
    "AB-U20-PDG.cpp"
)
source_group("Archivos de origen" FILES ${Archivos_de_origen})

set(Archivos_de_origen__CLI
    "CLI.cpp"
)
source_group("Archivos de origen\\CLI" FILES ${Archivos_de_origen__CLI})

set(Archivos_de_origen__Models__Abstract
    "AbsOrdernable.cpp"
    "AbsPersona.cpp"
    "AbsSearchable.cpp"
    "IDataProvider.cpp"
    "IRecord.cpp"
)
source_group("Archivos de origen\\Models\\Abstract" FILES ${Archivos_de_origen__Models__Abstract})

set(Archivos_de_origen__Models__Data
    "Cita.cpp"
    "Medico.cpp"
    "Paciente.cpp"
)
source_group("Archivos de origen\\Models\\Data" FILES ${Archivos_de_origen__Models__Data})

set(Archivos_de_origen__Models__DataProviders
    "DBProvider.cpp"
    "FileProvider.cpp"
)
source_group("Archivos de origen\\Models\\DataProviders" FILES ${Archivos_de_origen__Models__DataProviders})

set(Archivos_de_origen__Models__Managers
    "MedicoManager.cpp"
    "PacienteManager.cpp"
    "CitaManager.cpp"
)
source_group("Archivos de origen\\Models\\Managers" FILES ${Archivos_de_origen__Models__Managers})

set(ALL_FILES
    ${Archivos_de_encabezado}
    ${Archivos_de_encabezado__Abstract}
    ${Archivos_de_encabezado__CLI}
    ${Archivos_de_encabezado__Data}
    ${Archivos_de_encabezado__DataProviders}
    ${Archivos_de_encabezado__Managers}
    ${Archivos_de_origen}
    ${Archivos_de_origen__CLI}
    ${Archivos_de_origen__Models__Abstract}
    ${Archivos_de_origen__Models__Data}
    ${Archivos_de_origen__Models__DataProviders}
    ${Archivos_de_origen__Models__Managers}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE ABU20PDG)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASE "TRUE"
    )
endif()
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_CONSOLE;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "WIN32;"
        "_CONSOLE;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /Oi;
                /Gy
            >
            /permissive-;
            /std:c++17;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /Oi;
                /Gy
            >
            /permissive-;
            /sdl;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
            /DEBUG;
            /SUBSYSTEM:CONSOLE
        )
    endif()
endif()

################################################################################
# Dependencies
################################################################################
#use_package(${PROJECT_NAME} nlohmann.json 3.11.2)
