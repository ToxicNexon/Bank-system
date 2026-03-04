# Simple Bank System

A small banking program I made in C. I wanted to build something that actually does something useful instead of just printing "hello world" for the 10th time.

## What it does

- Create an account with your name and an opening balance
- Check your balance using your account ID
- Deposit and withdraw money
- Tells you if you don't have enough balance or if the account ID doesn't exist

## How to run it

```bash
gcc bank_system.c -o bank
./bank
```

Windows (MinGW):
```bash
gcc bank_system.c -o bank.exe
bank.exe
```

## Notes

- Accounts don't save when you close the program, it's all in memory
- Account IDs start from 1001 and go up
- Learned a lot about structs and why input validation actually matters (the program used to crash or loop forever without it)
