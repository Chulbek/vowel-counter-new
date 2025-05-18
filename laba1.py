# Функция для подсчета гласных букв (русских и английских)
def count_vowels(text):
    # Список гласных букв (русские и английские)
    vowels = 'аеёиоуыэюяАЕЁИОУЫЭЮЯaeiouAEIOU'
    # Подсчет гласных
    count = sum(1 for char in text if char in vowels)
    return count

# Тестирование программы
input_text = input("Введите строку: ")
result = count_vowels(input_text)
print(f"Количество гласных букв в строке: {result}")