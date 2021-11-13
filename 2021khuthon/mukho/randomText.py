import random

f = open('titleData.txt', 'r')

temp = []

for data in f:
    idx = data.index(' ')
    text = data[:idx] + '\t' + data[idx:-3] + '\t' + data[-1]
    temp.append(data.rstrip('\n'))

f.close()

f = open('newData.txt', 'w')

random.shuffle(temp)

for data in temp:
    text = data + '\n'
    f.write(text)

f.close()