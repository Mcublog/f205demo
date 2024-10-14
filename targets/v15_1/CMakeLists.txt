include(${PROJECT_SOURCE_DIR}/config/common.cmake)
include(${PROJECT_SOURCE_DIR}/config/mcu.cmake)

# Add sources
file(GLOB_RECURSE APP_SOURCES
    ${APP_DIR}/*.c
    ${APP_DIR}/*.cpp
)

file(GLOB_RECURSE HAL_SOURCES
    ${V15_1_CUBE_PATH}/Core/Src/*.c
    ${V15_1_CUBE_PATH}/Drivers/STM32F2xx_HAL_Driver/Src/*.c
)

file(GLOB_RECURSE HAL_USB_SOURCES

    ${V15_1_CUBE_PATH}/USB_DEVICE/App/*.c
    ${V15_1_CUBE_PATH}/USB_DEVICE/Target/*.c
    ${V15_1_CUBE_PATH}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/*.c
    ${V15_1_CUBE_PATH}/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/*.c

)

# Buid Boot target
add_executable(${V15_1_TARGET}
    ${APP_SOURCES}
    ${HAL_SOURCES}
    ${RTT_SOURCES}
    ${HAL_USB_SOURCES}
    ${V15_1_CUBE_PATH}/startup_stm32f205xx.s)

# Include paths
target_include_directories(${V15_1_TARGET} PRIVATE
    ${APP_DIR}
    ${DEBUG_DIR}
    # ${SMONSTER_INCLUDE_DIRS}
    ${HAL_INCLUDE_DIRS}
    ${RTT_INCLUDE_DIRS}
    ${V15_1_CUBE_PATH}/Drivers/CMSIS/Device/ST/STM32F2xx/Include
    ${V15_1_CUBE_PATH}/USB_DEVICE/App
    ${V15_1_CUBE_PATH}/USB_DEVICE/Target
    ${V15_1_CUBE_PATH}/Middlewares/ST/STM32_USB_Device_Library/Core/Inc
    ${V15_1_CUBE_PATH}/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
)

# Project symbols
target_compile_definitions(${V15_1_TARGET} PRIVATE ${symbols_SYMB})

# Compiler options
target_compile_options(${V15_1_TARGET}
    PRIVATE
    ${ARM_NONE_EABI_FLAGS}
    -Wno-missing-braces
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-volatile")

# Linker options
target_link_options(${V15_1_TARGET} PRIVATE ${F205_LINKER_OPTION})

# # Convert output to hex and binary
add_custom_command(TARGET ${V15_1_TARGET}
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_OBJCOPY} ARGS -O ihex -I elf32-littlearm ${V15_1_TARGET} ${V15_1_TARGET}.hex
    COMMAND ${CMAKE_OBJCOPY} ARGS -O binary -I elf32-littlearm ${V15_1_TARGET} ${V15_1_TARGET}.bin
)

build_jlink_script(${V15_1_TARGET})
