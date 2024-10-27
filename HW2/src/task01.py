def validation_user_input():
    """
    Возращает целое положительное число,
    введенное пользователем    
    """
    user_input = None
    while not user_input:
        try:
            user_input = int(input('Введите целое положительное число: '))
            if user_input >= 0x00 and user_input <= 0xffffff:
                return user_input
            else:
                print('Число должно быть положительное и меньше 16777215.')
                user_input = None
        except:
            print('Некорректный ввод, надо повторить.')
            user_input = None


def manual_convert(number):
    """
    Преобразует десятичное число в двоичное
    последовательным делением на 2
    """
    input_string = ''
    remainder = 0
    for i in range(24):
        remainder = number%2
        number = number//2
        if remainder == 0:
            print(f"{i} разряд --> 0")
            input_string = '0' + input_string
        else:
            print(f"{i} разряд --> 1")
            input_string = '1' + input_string
    return input_string


def bin_to_hex(quart):
    """
    Преобразует двоичную тетраду в 16-ую цифру 
    """
    if quart == "0000":
        return "0"
    elif quart == "0001":
        return "1"
    elif quart == "0010":    
        return "2"
    elif quart == "0011":
        return "3"
    elif quart == "0100":
        return "4"
    elif quart == "0101":
        return "5"
    elif quart == "0110":
        return "6"
    elif quart == "0111":
        return "7"
    elif quart == "1000":
        return "8"
    elif quart == "1001":
        return "9"
    elif quart == "1010":
        return "A"
    elif quart == "1011":
        return "B"
    elif quart == "1100":
        return "C"
    elif quart == "1101":
        return "D"
    elif quart == "1110":
        return "E"
    elif quart == "1111":
        return "F"


def convert_to_hex(binary):
    """
    Проебразует 24-разрядное 2-ое число в 
    6-разраядное 16-ое число
    """
    digit_1 = bin_to_hex(binary[0:4])
    digit_2 = bin_to_hex(binary[4:8])
    digit_3 = bin_to_hex(binary[8:12])
    digit_4 = bin_to_hex(binary[12:16])
    digit_5 = bin_to_hex(binary[16:20])
    digit_6 = bin_to_hex(binary[20:24])
    print(f"{binary[0:4]} --> {digit_1}")
    print(f"{binary[4:8]} --> {digit_2}")
    print(f"{binary[8:12]} --> {digit_3}")
    print(f"{binary[12:16]} --> {digit_4}")
    print(f"{binary[16:20]} --> {digit_5}")
    print(f"{binary[20:24]} --> {digit_6}")
    hex_result = digit_1 + digit_2 + digit_3 + digit_4 + digit_5 + digit_6
    return hex_result


if __name__ == "__main__":
    number = validation_user_input()
    print(f"Преобразуем {number} в двоичное число -->")
    binary = manual_convert(number)
    print(binary)
    print("Преобразуем двоичное в 16-ричное число -->")    
    hex_result = convert_to_hex(binary)
    print(hex_result)







