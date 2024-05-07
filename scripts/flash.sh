#!/usr/bin/env bash

openocd -f interface/wch-cmsis-dap.cfg -f target/stm32f4x.cfg -c "program $1 verify reset exit"
