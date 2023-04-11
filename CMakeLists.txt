cmake_minimum_required(VERSION 3.12)


#Pull in PICO SDK (must be before project)
include(pico_sdk_import.cmake)

project(gps_test C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#Initial SDK
pico_sdk_init()

add_executable(gps_test
        gps_test.c
        )


target_link_libraries(gps_test pico_stdlib hardware_uart)
	
#enable USB(by adding 1) and diable UART(by adding 0)
pico_enable_stdio_usb(gps_test 1)

pico_enable_stdio_uart(gps_test 0)

pico_add_extra_outputs(gps_test)


