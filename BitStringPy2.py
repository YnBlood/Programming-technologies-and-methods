class BitStringPy:
    def __init__(self, value=None):
        self.bs = ['0'] * 8

        if value is None:
            return

        if type(value) == BitStringPy:
            for i in range(8):
                self.bs[i] = value.bs[i]
        else:
            self.setString(value)

    def __del__(self):
        self.bs = []

    def getLen(self, bs):
        length = 0

        for _ in bs:
            length += 1

        return length

    def checkLen(self, bs):
        if self.getLen(bs) > 8:
            return False

        return True

    def checkBits(self, bs):
        length = self.getLen(bs)

        for i in range(length):
            if bs[i] != '0' and bs[i] != '1':
                return False

        return True

    def makeNewStr(self, bs, length):
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

    def setString(self, bs):
        if type(bs) == str:
            bs = list(bs)

        length = self.getLen(bs)
        self.bs = self.makeNewStr(bs, length)

    def fileInput(self, filename, num):
        try:
            fin = open(filename, "r", encoding="utf-8")
        except:
            return False

        lines = fin.readlines()
        fin.close()

        if num > len(lines):
            return False

        bs = list(lines[num - 1].strip())

        if not self.checkLen(bs) or not self.checkBits(bs):
            return False

        self.setString(bs)
        return True

    def output(self):
        print(''.join(self.bs))

    def getString(self):
        return ''.join(self.bs)

    def doAnd(self, b):
        c = BitStringPy()

        for i in range(8):
            if self.bs[i] == '1' and b.bs[i] == '1':
                c.bs[i] = '1'
            else:
                c.bs[i] = '0'

        return c

    def writeToFile(self, filename, text, append):
        try:
            if append:
                fout = open(filename, "a", encoding="utf-8")
            else:
                fout = open(filename, "w", encoding="utf-8")
        except:
            return False

        fout.write(text + self.getString() + "\n")
        fout.close()
        return True
