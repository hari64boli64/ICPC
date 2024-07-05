import os
import time
import subprocess as sb

char = str(__file__)[-4]
assert "A" <= char <= "Z"

os.chdir(os.path.dirname(__file__))

base = "/usr/bin/g++-13 -std=c++23 -std=gnu++23 -Dhari64 -Wall -Wextra -Wfatal-errors -Wno-unknown-pragmas -Wno-unused -Wno-unused-parameter -Wno-sign-compare -fdiagnostics-color=always -O3 -I/home/hari64boli64/Cpp -I/home/hari64boli64/ac-library-master "

print(f"now compiling {char}.cpp...")
c = sb.run(base + f"-o a.out {char}.cpp", shell=True)
if c.returncode != 0:
    print(f"NG: compile failed {char}.cpp")
    exit()

print("now compiling slow.cpp...")
c = sb.run(base + f"-o g.out slow.cpp", shell=True)
if c.returncode != 0:
    print("NG: compile failed slow.cpp")
    exit()

print("compile done.")

start = time.time()

print("Now running...")
while time.time() - start < 30:
    ok = True
    with open("input.txt", mode="w") as f_in:
        c = sb.run(["python3", "make_testcase.py"], stdout=f_in)
        # print("test gen")
        if c.returncode != 0:
            print("NG: make_input")
            ok = False
    s1 = ""
    s2 = ""
    with open("input.txt", encoding="UTF-8") as f_in:
        c = sb.run("./a.out < input.txt", shell=True, encoding="UTF-8", stdout=sb.PIPE)
        s1 = c.stdout.strip()
        if c.returncode != 0:
            print(f"NG: {char}.cpp")
            ok = False
        c = sb.run("./g.out < input.txt", shell=True, encoding="UTF-8", stdout=sb.PIPE)
        s2 = c.stdout.strip()
        if c.returncode != 0:
            print("NG: slow.cpp")
            print(c.stdout)
            ok = False
    if s1 != s2 or not ok:
        print("Different output found!")
        print(f"{char}.cpp:")
        print(s1)
        print("slow.cpp:")
        print(s2)
        print("NG")
        exit()

print("maybe OK")
