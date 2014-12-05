passed=0

for i in *.usr
do
	(diff $i ${i%\.*}.out -q || diff $i ${i%\.*}.out -y) && passed=$((passed+1));
done

echo "Sonucun muthis kenkz: $passed/$(ls -la *.out | wc -l)"
