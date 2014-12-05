for i in *.in
do
	echo "Solving ${i%\.*}"
	cp $i input.txt
	./sol
	mv output.txt ${i%\.*}.usr
done
