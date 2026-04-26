from BitStringPy import BitStringPy


a = BitStringPy()
b = BitStringPy()
c = BitStringPy()

lenA = 0
lenB = 0

way = int(input("Выберите способ ввода:\n1 - с консоли\n2 - из файла\n"))

if way == 1:
    str1 = list(input("Введите первую битовую строку:"))
    str2 = list(input("Введите вторую битовую строку:"))

    for _ in str1:
        lenA += 1

    for _ in str2:
        lenB += 1

    if lenA > 8 or lenB > 8:
        print("Ошибка! Длина строки больше 8 бит.")
        exit()

    if not a.checkBits(str1):
        print("Ошибка! Первая строка введена некорректно.")
        exit()

    if not b.checkBits(str2):
        print("Ошибка! Вторая строка введена некорректно.")
        exit()

    a.setString(str1)
    b.setString(str2)
elif way == 2:
    if not a.fileInput("input.txt", 1) or not b.fileInput("input.txt", 2):
        print("Ошибка! Файл не открылся.")
        exit()

    print("Первая строка из файла:", a.getString())
    print("Вторая строка из файла:", b.getString())
else:
    print("Ошибка! Неверный способ ввода.")
    exit()

print("Измененная 1 строка:", a.getString())
print("Измененная 2 строка:", b.getString())

c = a.doAnd(b)

print("Результат AND:", c.getString())

if a.writeToFile("output.txt", "Измененная 1 строка: ", False) and \
        b.writeToFile("output.txt", "Измененная 2 строка: ", True) and \
        c.writeToFile("output.txt", "Результат AND: ", True):
    print("Результат записан в файл output.txt")
else:
    print("Ошибка! Не удалось записать результат в файл.")
