set startTime [clock seconds]
puts "Start Time: [clock format $startTime -format %D\ %H:%M:%S]"

if { [info exists ::env(ELF_FILE_0)] } {
  set elf_path $env(ELF_FILE_0) 
} elseif { $argc != 1 } {
    puts stderr "Elf path required as input"
    exit 1
} else {
    set elf_path [lindex $argv 0]
}

# Connect to fast programmer if required
set jtag_serial $env(JTAG_SERIAL)
if { [info exists ::env(PROGRAMMER_ADDRESS)] } {
    set programmer_address $env(PROGRAMMER_ADDRESS)
    puts "INFO: Connecting to SmartLynq programmer (SN: $jtag_serial) at $programmer_address:3121"
    connect -url $programmer_address:3121
    jtag target 1
    set ffast 10000000
} else {
    puts "INFO: Connecting to localhost programmer (SN: $jtag_serial)"
    connect

    # Increase JTAG Target Frequency
    jtag targets -set -filter { (name =~ "xcku040" || name =~ "xcku060") && jtag_cable_serial =~ "$jtag_serial" }
    set flist [jtag frequency -list]
    set length [llength $flist]
    set ffast [lindex $flist $length-1]
}
puts "INFO: Programing rate of $ffast bits/sec determined"
jtag frequency $ffast

# Download elf to mb0
targets -set -nocase -filter { name =~ "microblaze*#0"  && jtag_cable_serial =~ "$jtag_serial" }
catch { stop }
after 100
rst

after 2000
puts "INFO: Downloading ELF file: $elf_path"
dow  $elf_path
after 2000
con

set stopTime [clock seconds]
puts "End Time: [clock format $stopTime -format %D\ %H:%M:%S]"
puts "Delta Time: [clock format [expr $stopTime - $startTime] -format %M:%S]"

if { $argc == 1 } {
exit 0
}
