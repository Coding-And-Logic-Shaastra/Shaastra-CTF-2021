#flag = ShaastraCTF{Cheem$_i$_L0ve_007}
#flag in hex = 53686161737472614354467b436865656d245f69245f4c3076655f3030377d
#flag after xor with "cheems" = 5f86616d9d747e8f4358a87b4f866569832453872453a2307a8b5f3cde3771

str = "5f86616d9d747e8f4358a87b4f866569832453872453a2307a8b5f3cde3771" 
i = 1
for x in str:
    num = 0
    if x >= '0' and x <= '9':
        num = int(x)
    else:
        num = ord(x) - ord('a') + 10
    val = pow(num, i)
    i += 1
    print(val)
