include(${PROJECT_SOURCE_DIR}/config/common.cmake)
include(${PROJECT_SOURCE_DIR}/config/mcu.cmake)

# Add sources
file(GLOB_RECURSE APP_SOURCES
    ${APP_DIR}/*.c
)

file(GLOB_RECURSE HAL_SOURCES
    ${STM32F205_CUBE_PATH}/Core/Src/*.c
    ${STM32F205_CUBE_PATH}/Drivers/STM32F2xx_HAL_Driver/Src/*.c
)

file(GLOB_RECURSE HAL_USB_SOURCES

    ${STM32F205_CUBE_PATH}/USB_DEVICE/App/*.c
    ${STM32F205_CUBE_PATH}/USB_DEVICE/Target/*.c
    ${STM32F205_CUBE_PATH}/Middlewares/ST/STM32_USB_Device_Library/Core/Src/*.c
    ${STM32F205_CUBE_PATH}/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/*.c

)

# Buid Boot target
add_executable(${F205_TARGET}
    ${APP_SOURCES}
    ${HAL_SOURCES}
    ${RTT_SOURCES}
    ${HAL_USB_SOURCES}
    ${STM32F205_CUBE_PATH}/startup_stm32f205xx.s)

# Include paths
target_include_directories(${F205_TARGET} PRIVATE
    ${APP_DIR}
    ${DEBUG_DIR}
    # ${SMONSTER_INCLUDE_DIRS}
    ${HAL_INCLUDE_DIRS}
    ${RTT_INCLUDE_DIRS}
    ${STM32F205_CUBE_PATH}/Drivers/CMSIS/Device/ST/STM32F2xx/Include
    ${STM32F205_CUBE_PATH}/USB_DEVICE/App
    ${STM32F205_CUBE_PATH}/USB_DEVICE/Target
    ${STM32F205_CUBE_PATH}/Middlewares/ST/STM32_USB_Device_Library/Core/Inc
    ${STM32F205_CUBE_PATH}/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc
)

# Project symbols
target_compile_definitions(${F205_TARGET} PRIVATE ${symbols_SYMB})

# Compiler options
target_compile_options(${F205_TARGET}
    PRIVATE
    ${ARM_NONE_EABI_FLAGS}
    -Wno-missing-braces
    -Wno-pointer-sign
)

# Linker options
target_link_options(${F205_TARGET} PRIVATE ${F205_LINKER_OPTION})

# # Convert output to hex and binary
add_custom_command(TARGET ${F205_TARGET}
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND ${CMAKE_OBJCOPY} ARGS -O ihex -I elf32-littlearm ${F205_TARGET} ${F205_TARGET}.hex
    COMMAND ${CMAKE_OBJCOPY} ARGS -O binary -I elf32-littlearm ${F205_TARGET} ${F205_TARGET}.bin
)

build_jlink_script(${F205_TARGET})
