d = "AHIMOoTUVvWwXxY"
s = input()
lens = (int)(len(s) / 2)
for i in range(lens + 1):
    if not ((s[i] in d and s[i] == s[ - i - 1]) or s[i] + s[ -i-1] in ["bd", "db", "pq", "qp"]):
        print("NIE")
        break
else:
    print("TAK")

