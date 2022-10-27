def func(s):
    return "".join(list(map((lambda x: "#"+x), s.split())))
print((func("salam lakom")))
