include(${PROJECT_SOURCE_DIR}/config/common.cmake)
include(${PROJECT_SOURCE_DIR}/config/mcu.cmake)


# region HAL
set(HAL_INCLUDE_DIRS
    # Put here your include dirs, one in each line, relative to CMakeLists.txt file location
    ${V14_CUBE_PATH}/Core/Inc
    ${V14_CUBE_PATH}/Drivers/STM32F2xx_HAL_Driver/Inc
    ${V14_CUBE_PATH}/Drivers/STM32F2xx_HAL_Driver/Inc/Legacy
    ${V14_CUBE_PATH}/Drivers/CMSIS/Device/ST/STM32F2xx/Include
    ${V14_CUBE_PATH}/Drivers/CMSIS/Include
)
# endregion

# Add sources
file(GLOB_RECURSE APP_SOURCES
    ${APP_DIR}/*.c
    ${APP_DIR}/*.cpp
)

file(GLOB_RECURSE HAL_SOURCES
    ${V14_CUBE_PATH}/Core/Src/*.c
    ${V14_CUBE_PATH}/Drivers/STM32F2xx_HAL_Driver/Src/*.c
)

set(USB_MIDDLEWARES ${V14_CUBE_PATH}/Middlewares/ST/STM32_USB_Device_Library)
set(USB_DEVICE      ${V14_CUBE_PATH}/USB_DEVICE)

file(GLOB_RECURSE HAL_USB_SOURCES

    ${USB_MIDDLEWARES}/*.c
    ${USB_DEVICE}/*.c
)

list(REMOVE_ITEM APP_SOURCES ${PROJECT_SOURCE_DIR}/app/ee24/ee24.c)

# Buid Boot target
add_executable(${V14_TARGET}
    ${APP_SOURCES}
    ${HAL_SOURCES}
    ${RTT_SOURCES}
    ${HAL_USB_SOURCES}
    ${V14_CUBE_PATH}/startup_stm32f205xx.s)

# Include paths
target_include_directories(${V14_TARGET} PRIVATE
    ${PROJECT_SOURCE_DIR}
    ${APP_DIR}
    ${DEBUG_DIR}
    # ${SMONSTER_INCLUDE_DIRS}
    ${HAL_INCLUDE_DIRS}
    ${RTT_INCLUDE_DIRS}
    ${V14_CUBE_PATH}/Composite
    ${V14_CUBE_PATH}/Drivers/CMSIS/Device/ST/STM32F2xx/Include

    ${USB_MIDDLEWARES}/Class/CDC/Inc
    ${USB_MIDDLEWARES}/Core/Inc
    ${USB_DEVICE}/App
    ${USB_DEVICE}/Target
)

# Project symbols
target_compile_definitions(${V14_TARGET} PRIVATE ${symbols_SYMB} "REV14")

# Compiler options
target_compile_options(${V14_TARGET}
    PRIVATE
    ${ARM_NONE_EABI_FLAGS}
    -Wno-missing-braces
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-volatile")

# Linker options
target_link_options(${V14_TARGET} PRIVATE ${F205_LINKER_OPTION})

# # Convert output to hex and binary
add_custom_command(TARGET ${V14_TARGET}
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_OBJCOPY} ARGS -O ihex -I elf32-littlearm ${V14_TARGET} ${V14_TARGET}.hex
    COMMAND ${CMAKE_OBJCOPY} ARGS -O binary -I elf32-littlearm ${V14_TARGET} ${V14_TARGET}.bin
)

build_jlink_script(${V14_TARGET})
