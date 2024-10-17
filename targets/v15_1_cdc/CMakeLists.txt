include(${PROJECT_SOURCE_DIR}/config/common.cmake)
include(${PROJECT_SOURCE_DIR}/config/mcu.cmake)


# region HAL
set(HAL_INCLUDE_DIRS
    # Put here your include dirs, one in each line, relative to CMakeLists.txt file location
    ${V15_1_CDC_CUBE_PATH}/Core/Inc
    ${V15_1_CDC_CUBE_PATH}/Drivers/STM32F2xx_HAL_Driver/Inc
    ${V15_1_CDC_CUBE_PATH}/Drivers/STM32F2xx_HAL_Driver/Inc/Legacy
    ${V15_1_CDC_CUBE_PATH}/Drivers/CMSIS/Device/ST/STM32F2xx/Include
    ${V15_1_CDC_CUBE_PATH}/Drivers/CMSIS/Include
)
# endregion

# Add sources
file(GLOB_RECURSE APP_SOURCES
    ${APP_DIR}/*.c
    ${APP_DIR}/*.cpp
)

file(GLOB_RECURSE HAL_SOURCES
    ${V15_1_CDC_CUBE_PATH}/Core/Src/*.c
    ${V15_1_CDC_CUBE_PATH}/Drivers/STM32F2xx_HAL_Driver/Src/*.c
)

set(USB_MIDDLEWARES ${V15_1_CDC_CUBE_PATH}/Middlewares/ST/STM32_USB_Device_Library)
set(USB_DEVICE      ${V15_1_CDC_CUBE_PATH}/USB_DEVICE)

file(GLOB_RECURSE HAL_USB_SOURCES

    ${USB_MIDDLEWARES}/*.c
    ${USB_DEVICE}/*.c
)

list(REMOVE_ITEM APP_SOURCES ${PROJECT_SOURCE_DIR}/app/ee24/ee24.c)

# Buid Boot target
add_executable(${V15_1_CDC_TARGET}
    ${APP_SOURCES}
    ${HAL_SOURCES}
    ${RTT_SOURCES}
    ${HAL_USB_SOURCES}
    ${V15_1_CDC_CUBE_PATH}/startup_stm32f205xx.s)

# Include paths
target_include_directories(${V15_1_CDC_TARGET} PRIVATE
    ${APP_DIR}
    ${DEBUG_DIR}
    # ${SMONSTER_INCLUDE_DIRS}
    ${HAL_INCLUDE_DIRS}
    ${RTT_INCLUDE_DIRS}
    ${V15_1_CDC_CUBE_PATH}/Composite
    ${V15_1_CDC_CUBE_PATH}/Drivers/CMSIS/Device/ST/STM32F2xx/Include

    ${USB_MIDDLEWARES}/Class/CDC/Inc
    ${USB_MIDDLEWARES}/Core/Inc
    ${USB_DEVICE}/App
    ${USB_DEVICE}/Target
)

# Project symbols
target_compile_definitions(${V15_1_CDC_TARGET} PRIVATE ${symbols_SYMB})

# Compiler options
target_compile_options(${V15_1_CDC_TARGET}
    PRIVATE
    ${ARM_NONE_EABI_FLAGS}
    -Wno-missing-braces
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-volatile")

# Linker options
target_link_options(${V15_1_CDC_TARGET} PRIVATE ${F205_LINKER_OPTION})

# # Convert output to hex and binary
add_custom_command(TARGET ${V15_1_CDC_TARGET}
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_OBJCOPY} ARGS -O ihex -I elf32-littlearm ${V15_1_CDC_TARGET} ${V15_1_CDC_TARGET}.hex
    COMMAND ${CMAKE_OBJCOPY} ARGS -O binary -I elf32-littlearm ${V15_1_CDC_TARGET} ${V15_1_CDC_TARGET}.bin
)

build_jlink_script(${V15_1_CDC_TARGET})
