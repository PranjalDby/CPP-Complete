def Bin(num):
    if(num < 1):
        print("0",end="")
        return
    
    Bin(num // 2)
    res = num % 2
    print(res,end="")



if __name__ == '__main__':
    num = int(input("Enter: "))
    Bin(num);