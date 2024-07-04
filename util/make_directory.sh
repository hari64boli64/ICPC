for char in {A..H}
do
    mkdir ICPC2024/$char
    cp util/template.cpp ICPC2024/$char/$char.cpp
    cp util/template.cpp ICPC2024/$char/slow.cpp
    cp util/check.py ICPC2024/$char/check_$char.py
    cp util/make_testcase.py ICPC2024/$char/make_testcase.py
done