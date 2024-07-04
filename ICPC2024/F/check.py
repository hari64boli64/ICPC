import subprocess as sb
import random
import time
import sys

start = time.time()

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
            print("NG: main.cpp")
            ok = False
        c = sb.run("./g.out < input.txt", shell=True, encoding="UTF-8", stdout=sb.PIPE)
        s2 = c.stdout.strip()
        if c.returncode != 0:
            print("NG: guchoku.cpp")
            print(c.stdout)
            ok = False
    if s1 != s2 or not ok:
        print(s1)
        print(s2)
        print("NG")
        quit()
print("maybe OK")
