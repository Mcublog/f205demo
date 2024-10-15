# region MCU GLOBAL PROPERTY
set(V15_1_CDC_TARGET               fw_cdc_rev15_1)

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

# region RTT
set(RTT_LIB rtt)
set(RTT_VERSION SEGGER_RTT_V762c)
set(RTT_DIR ${LIBS_DIR}/${RTT_VERSION})
set(RTT_INCLUDE_DIRS
    ${RTT_DIR}/Config
    ${RTT_DIR}/RTT)
# Add sources
file(GLOB_RECURSE RTT_SOURCES
    ${RTT_DIR}/RTT/*.c
    ${RTT_DIR}/RTT/*.S
    ${RTT_DIR}/Syscalls/SEGGER_RTT_Syscalls_GCC.c
)

# endregion

# region SerialMonster
set(SMONSTER_DIR ${LIBS_DIR}/serial_monster)
set(SMONSTER_INCLUDE_DIRS
    ${SMONSTER_DIR}/include)
# Add sources
file(GLOB_RECURSE SMONSTER_SOURCES
    ${SMONSTER_DIR}/sources/*.c
)
# endregion


# Put here your symbols (preprocessor defines), one in each line
# Encapsulate them with double quotes for safety purpose
set(symbols_SYMB
    $<$<CONFIG:DEBUG>:"DEBUG">
    $<$<CONFIG:RELASE>:"NDEBUG">
    "USE_HAL_DRIVER"
    "STM32F205xx"
    "USE_FULL_LL_DRIVER"
)

set(CPU_PARAMETERS -mthumb
    # This needs attention to properly set for used MCU
    -mcpu=cortex-m3
    -mfloat-abi=soft)

set(ARM_NONE_EABI_FLAGS
    ${CPU_PARAMETERS}
    # -Wall
    # -Wextra
    # -Wpedantic
    -fdata-sections
    -ffunction-sections
    -fdiagnostics-color=always
    # Full debug configuration
    $<$<CONFIG:DEBUG>: -Og -g3 -ggdb>
    # Release
    $<$<CONFIG:RELEASE>:-Os -s>
    # Release with DEBUG
    $<$<CONFIG:RelWithDebInfo>:-Os -g3 -ggdb>
)

# Set linker script
set(F205_LINKER_SCRIPT ${PROJECT_SOURCE_DIR}/cubemx/v15_1/STM32F205RGTx_FLASH.ld)

set(F205_LINKER_OPTION
    -T${F205_LINKER_SCRIPT}
    ${CPU_PARAMETERS}
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map
    -lc
    -lm
    -lnosys
    -specs=nano.specs
    -specs=nosys.specs
    # -u _printf_float                # STDIO float formatting support
    -Wl,--start-group
    -fno-exceptions
    -fno-rtti
    -Wno-unused-parameter
    -Wno-sign-compare
    -Wno-pointer-sign
    -Wno-volatile
    -Wl,--end-group
    -Wl,--print-memory-usage
    -Wl,--gc-sections # removed unused functions
)
# endregion