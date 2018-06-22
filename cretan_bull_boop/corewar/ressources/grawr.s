.name "GRAWR"
.comment "GRAWRAWRRAWWAAWAWAWRRRAWRRRR"

l2:		sti r1, %:live, %1
		sti	r1, %:kill, %1
		and r1, %0, r1

		fork %:kill

live:	live %1
		zjmp %:live

kill:	live %1
