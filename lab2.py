a = list(input("Введите первую битовую строку:"))
b = list(input("Введите вторую битовую строку:"))

lenA = 0
lenB = 0

for _ in a:
    lenA += 1

for _ in b:
    lenB += 1

if lenA > 8 or lenB > 8:
    print("Ошибка! Длина строки больше 8 бит.")
    exit()

for i in range(lenA):
    if a[i] != '0' and a[i] != '1':
        print("Ошибка! Первая строка введена некорректно.")
        exit()

for i in range(lenB):
    if b[i] != '0' and b[i] != '1':
        print("Ошибка! Вторая строка введена некорректно.")
        exit()

new_a = ['0'] * 8
i = 7
while i>= 0:
    if lenA >0:
        new_a[i] =a[lenA - 1]
        lenA -= 1
    else:
        new_a[i] = '0'
    i -= 1

new_b = ['0'] * 8
i = 7
while i >= 0:
    if lenB > 0:
        new_b[i] = b[lenB - 1]
        lenB -= 1
    else:
        new_b[i] = '0'
    i -= 1

b = new_b
print("Измененная 2 строка:", ''.join(b))

for i in range(8):
    if a[i] == '1' and b[i] == '1':
        a[i] = '1'
    else:
        a[i] = '0'

print("Результат AND:", ''.join(a))