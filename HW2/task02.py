def validation_user_input():
    """
    Возращает целое положительное число,
    введенное пользователем    
    """
    user_input = None
    while not user_input:
        try:
            user_input = input('Введите 16-чное число: ')
            int(user_input, 16) # валидация на корректность введенной строки
            return user_input
        except:
            print('Некорректный ввод, надо повторить.')
            user_input = None


def hex_to_dec(input_string):
    """
    Преобразует 16-ричную цифровую строку в десятичное число
    """
    dec_number = 0
    input_str_len = len(input_string)
    for i in range(input_str_len):
        a = int(input_string[i], 16)
        n = input_str_len - 1 -i
        dec_number += a * 16** n
        print(f"{a} * 16 ^ {n} +")          
    print('-'*20,f'\n = {dec_number}')
    return dec_number


if __name__ == '__main__':
    user_input = (validation_user_input())
    print(f'Результат преобразования числа {user_input} -->\n', '-' * 20)
    hex_to_dec(user_input)

