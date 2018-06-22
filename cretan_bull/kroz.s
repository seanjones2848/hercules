.name "kroz"
.comment "EVIIIILA M'I"

l2:		;fork %:kill
		sti r1, %:liver, %1
		and r1, %0, r2

liver:	live %1
		fork %:kill
		zjmp %:liver

kill:	live %1
