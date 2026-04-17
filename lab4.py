def getLen(bs):
    length = 0

    for _ in bs:
        length += 1

    return length


def checkLen(bs):
    if getLen(bs) > 8:
        return False

    return True


def checkBits(bs):
    length = getLen(bs)

    for i in range(length):
        if bs[i] != '0' and bs[i] != '1':
            return False

    return True


def makeNewStr(bs, length):
    new_bs = ['0'] * 8
    i = 7

    while i >= 0:
        if length > 0:
            new_bs[i] = bs[length - 1]
            length -= 1
        else:
            new_bs[i] = '0'
        i -= 1

    return new_bs


def doAnd(a, b):
    for i in range(8):
        if a[i] == '1' and b[i] == '1':
            a[i] = '1'
        else:
            a[i] = '0'

    return a


def readFromFile():
    try:
        fin = open("input.txt", "r", encoding="utf-8")
    except:
        return None, None

    a = list(fin.readline().strip())
    b = list(fin.readline().strip())

    fin.close()
    return a, b


def writeToFile(a, b):
    try:
        fout = open("output.txt", "w", encoding="utf-8")
    except:
        return False

    fout.write("Измененная 1 строка: " + ''.join(a) + "\n")
    fout.write("Измененная 2 строка: " + ''.join(b) + "\n")
    fout.write("Результат AND: " + ''.join(a) + "\n")

    fout.close()
    return True


way = int(input("Выберите способ ввода:\n1 - с консоли\n2 - из файла\n"))

if way == 1:
    a = list(input("Введите первую битовую строку:"))
    b = list(input("Введите вторую битовую строку:"))
elif way == 2:
    a, b = readFromFile()

    if a is None or b is None:
        print("Ошибка! Файл не открылся.")
        exit()

    print("Первая строка из файла:", ''.join(a))
    print("Вторая строка из файла:", ''.join(b))
else:
    print("Ошибка! Неверный способ ввода.")
    exit()

lenA = 0
lenB = 0

for _ in a:
    lenA += 1

for _ in b:
    lenB += 1

if not checkLen(a) or not checkLen(b):
    print("Ошибка! Длина строки больше 8 бит.")
    exit()

if not checkBits(a):
    print("Ошибка! Первая строка введена некорректно.")
    exit()

if not checkBits(b):
    print("Ошибка! Вторая строка введена некорректно.")
    exit()

a = makeNewStr(a, lenA)
print("Измененная 1 строка:", ''.join(a))

b = makeNewStr(b, lenB)
print("Измененная 2 строка:", ''.join(b))

a = doAnd(a, b)

print("Результат AND:", ''.join(a))

if writeToFile(a, b):
    print("Результат записан в файл output.txt")
else:
    print("Ошибка! Не удалось записать результат в файл.")
