set -e

read -p "Which Problem? (A-H) " input
char=$(echo $input | tr '[:lower:]' '[:upper:]')

read -r -p "Do Compile? [Y/N] " response
if [[ "$response" =~ ^([yY][eE][sS]|[yY])$ ]]
then
    /usr/bin/g++ ICPC2024/$char/$char.cpp -std=c++23 -std=gnu++23 -Dhari64 -Wall -Wextra -Wfatal-errors -Wno-unknown-pragmas -Wno-unused -Wno-unused-parameter -Wno-sign-compare -fdiagnostics-color=always -O3 -I/home/hari64boli64/Cpp -I/home/hari64boli64/ac-library-master
fi

read -p "Which test case? (1-3) " input
num=$input

echo "Running ICPC2024/$char/a.out with ICPC2024/$char/${char}${num}"
./ICPC2024/$char/a.out < ICPC2024/$char/${char}${num} > ICPC2024/$char/answer_${char}${num}.txt

echo "Done."
