set -e

echo "Which Problem? (A-H)"
read input
char=$(echo $input | tr '[:lower:]' '[:upper:]')

echo "Which test case? (1-3)"
read input
num=$input

echo "Running ICPC2024/$char/a.out with ICPC2024/$char/${char}${num}"
./ICPC2024/$char/a.out < ICPC2024/$char/${char}${num} > ICPC2024/$char/answer_${char}${num}.txt

echo "Done."
