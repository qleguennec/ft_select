WORDS="test/words.txt"

if [ "$#" -ne 1 ]; then
	echo "not enough args"
	exit 1
fi


ARGS=$(cat "$WORDS" | python -c 'import sys, random; L = sys.stdin.readlines();
random.shuffle(L); print "".join(L),' | head -n "$1" | tr '\n' ' ')

./ft_select $ARGS
