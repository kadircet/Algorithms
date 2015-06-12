for i in *.in
do
	echo "Solving ${i%\.*}"
	cp $i input.txt
	timeout 1s ./sol
	mv output.txt ${i%\.*}.usr
done
