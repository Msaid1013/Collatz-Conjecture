def collatz_Conjecture(num):
    while num > 1:
        print(num)
        if (num % 2 == 0):
            num = num//2
        else:
            num = 3 * num + 1
    print(1)
 
 
num = int(input('Enter a number: '))
print(f'Collatz Conjecture for {num}')
collatz_Conjecture(num)
