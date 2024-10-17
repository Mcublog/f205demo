# region GLOBAL PROPERTIES
set(V15_1_CDC_CUBE_PATH           ${PROJECT_SOURCE_DIR}/cubemx/v15_1)
set(V15_1_COMP_CUBE_PATH          ${PROJECT_SOURCE_DIR}/cubemx/v15_1_composite)
set(DESKTOP_TARGET_PATH           ${PROJECT_SOURCE_DIR}/targets/desktop)

set(APP_DIR     ${PROJECT_SOURCE_DIR}/app)
set(DEBUG_DIR   ${APP_DIR}/debug)
set(LIBS_DIR    ${PROJECT_SOURCE_DIR}/libs)

set(APP_DIRS
    ${APP_DIR}
    ${DEBUG_DIR}
    ${UTILS_DIR}
    ${IO_DIR}
)

set(COMMON_TYPES_TARGET common_types_test)
set(TEST_DIR            ${PROJECT_SOURCE_DIR}/test)

set(GCC_EMBEDDED    arm-none-eabi-gcc)
set(GCC_DESKTOP     gcc)