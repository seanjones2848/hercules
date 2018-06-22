./mangercentos & PID=$!
kill -14 $PID
echo "Dearest King, The horses have been coralled, would you like them tamedor to remain wild? (t/w)"
read ans 
case $ans in
	't') ./wild 0 & echo "Here are your tamed horses." ;;
	'w') ./wild 1 & echo "You asked for it..." ;;
	'*') echo "You failed to pick an option" ;;
esac
