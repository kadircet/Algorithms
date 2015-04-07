(gcc *.c -osol || echo "derleyemedik :("; exit 1) && ./solver.sh && ./match.sh && rm -f sol
