set val(mac)            Mac/BNEP    ;# set MAC type to bluetooth
set val(nn)             7               ;# number of btnodes

set ns	[new Simulator]
$ns node-config -macType $val(mac) 	;# set node type to BTNode

for {set i 0} {$i < $val(nn) } {incr i} {
    set node($i) [$ns node $i ]
    # $node($i) rt Manual
    $node($i) rt AODV
    $node($i) SchedAlgo PRR
    $node($i) BrAlgo TDRP
    set lmp [$node($i) set lmp_]
    $lmp set defaultTSniff_ 256
    $lmp set defaultSniffAttempt_ 128
    $ns at 0.0 "$node($i) on"       ;# An random delay up to 2 slots applied.
    $node($i) set-statist 7 15 1 adjust-l2cap-hdr
}

$node(0) LossMod BlueHoc			;# turn on LossMod for all nodes
 $node(0) trace-all-NULL on	
 $node(0) trace-all-POLL on	
# $node(0) trace-all-in-air on	

set udp0 [new Agent/UDP]
$ns attach-agent $node(3) $udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0

$cbr0 set packetSize_ 30		;# playload size for HV3
$cbr0 set interval_ [expr 625e-6 * 6]	;# T_poll = 6

set null0 [new Agent/Null]
$ns attach-agent $node(6) $null0

$ns connect $udp0 $null0

$udp0 set packetSize_ 1400
$cbr0 set packetSize_ 1349
$cbr0 set interval_ 0.015

# $ns at 0.2 "$cbr0 start"

 set nscmd "$cbr0 start"

$node(0) setall_scanWhenOn 0

# make connections.
# When the connection is ready, "$nscmd" will be
# invoked to generate higher layer traffic.
$ns at 0.01 "$node(0) make-pico-fast DH5 DH5 1 2"
$ns at 0.1 "$node(1) make-pico-fast DH5 DH5 3 4"
$ns at 0.3 "$node(2) make-pico-fast DH5 DH5 5 6"

$ns at 5 "$cbr0 start"

proc finish {} {
    global node
    $node(0) print-all-stat
    exit 0
}
                                                                                
$ns at 15.01 "finish"

$ns run

