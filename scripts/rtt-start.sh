#!/bin/bash

openocd -f interface/wch-cmsis-dap.cfg -f target/stm32f4x.cfg -f interface/rtt.cfg
    # -f chip/st/stm32/stm32.tcl -l output.log -d
    # -s tcl -c "rtt setup 0x20000000 2048 \"SEGGER RTT\"" -c "rtt start" -c "rtt server start 9090 0"
    # -c "rtt setup 0x20000000 2048 \"SEGGER RTT\" \
    # rtt start \
    # rtt server start 9090 0"
