passed=0

for i in *.usr
do
	(diff $i ${i%\.*}.out -Zq || diff $i ${i%\.*}.out -y) && passed=$((passed+1));
done

success=$((100*$passed/$(ls -la *.out | wc -l)))

echo -n "Sonucun "

if [ $success -ge 100 ]
	then
	echo -n "muthis"
elif [ $success -ge 90 ]
	then
	echo -n "yakisikli"
else
	echo -n "yakiyo"
fi

echo " kenkz: $passed/$(ls -la *.out | wc -l)"
