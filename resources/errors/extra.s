.name "zork"
.comment "just a basic living prog"

l2:		sti r100,%:live,%1
		and r1,%0,,,,,,,,r1
live:   live %1 aaaaaaaaaa
		zjmp %:live