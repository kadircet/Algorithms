((gcc *.c -osol; echo "derledik") || (echo "derleyemedik :("; exit 1))
./solver.sh && ./match.sh && rm -f sol
