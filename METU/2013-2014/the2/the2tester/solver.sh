for i in *.in
do
	./sol < $i > ${i%\.*}.usr;
done
