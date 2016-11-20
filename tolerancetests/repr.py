file = open('repr', 'r')

for x in range(0, 6):
    tolerance = file.readline()
    l = 0
    for y in range(0, 100):
        ids = (file.readline()).split(" ")
        l += len(ids)
    print(tolerance, ":", l/100)