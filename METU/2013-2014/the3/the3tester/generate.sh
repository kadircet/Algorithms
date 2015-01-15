if [ -z $1 ]
	then
	echo "usage: $0 number_of_testcases"
	exit 1;
fi

(gcc *.c -omaster; echo "derledik") || (echo "koduunu derleyemedik :("; exit 1)

for i in $(seq 0 $(($1-1)))
do
	echo "Generating case_$i"
	./gen > case_$i.in
	./master < case_$i.in > case_$i.out
	sleep 1
done
