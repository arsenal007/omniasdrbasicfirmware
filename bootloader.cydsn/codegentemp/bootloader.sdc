# THIS FILE IS AUTOMATICALLY GENERATED
# Project: J:\Ham Radio\ominaSDR\Hardware\Omnia-basic\firmware\omnia-sdr-basic\bootloader.cydsn\bootloader.cyprj
# Date: Tue, 23 Feb 2016 14:17:04 GMT
#set_units -time ns
create_clock -name {CyXTAL} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/xtal}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {MORSE_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 24001 48001} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_clock -name {MORSE_CLK(fixed-function)} -period 1000000 -waveform {0 41.6666666666667} [get_pins {ClockBlock/dclk_glb_ff_0}]

set_false_path -from [get_pins {__ZERO__/q}]

# Component constraints for J:\Ham Radio\ominaSDR\Hardware\Omnia-basic\firmware\omnia-sdr-basic\bootloader.cydsn\TopDesign\TopDesign.cysch
# Project: J:\Ham Radio\ominaSDR\Hardware\Omnia-basic\firmware\omnia-sdr-basic\bootloader.cydsn\bootloader.cyprj
# Date: Tue, 23 Feb 2016 14:16:56 GMT
