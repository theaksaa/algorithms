for((i = 1; i <= 100000; i++)); do
	echo $i
	./gen $i > generated
	if cmp -s <(./solution < generated) <(./brute < generated); then
		echo -e "\e[1m\e[92m Accepted \e[0m";
	else
		echo -e "\e[1m\e[91m WRONG ANSWER \e[0m";
		break;
	fi
done
