import subprocess as sb
import random
import time
import sys
import os

os.chdir(os.path.dirname(__file__))

start = time.time()

while time.time() - start < 30:
    ok = True
    with open("our_testcase.txt", mode="w") as f_in:
        c = sb.run(["python3", "make_testcase.py"], stdout=f_in)
        if c.returncode != 0:
            print("NG: make_input")
            ok = False
    s1 = ""
    s2 = ""
    c = sb.run(
        "./a.out < our_testcase.txt", shell=True, encoding="UTF-8", stdout=sb.PIPE
    )
    s1 = c.stdout.strip()
    if c.returncode != 0:
        print("NG: a.out")
        ok = False
    c = sb.run(
        "./g.out < our_testcase.txt", shell=True, encoding="UTF-8", stdout=sb.PIPE
    )
    s2 = c.stdout.strip()
    if c.returncode != 0:
        print("NG: g.out")
        print(c.stdout)
        ok = False
    if s1 != s2 or not ok:
        print("a.out:")
        print(s1)
        print("g.out:")
        print(s2)
        print("NG")
        quit()
print("maybe OK")
