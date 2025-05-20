#include <iostream>
#include <string>
#include <io.h>      // _setmode
#include <fcntl.h>   // _O_U16TEXT

// Функция для подсчёта русских и английских гласных в std::wstring
int countVowels(const std::wstring& str) {
    // Объединяем русские и английские гласные
    const std::wstring vowels =
        L"аеёиоуыэюяАЕЁИОУЫЭЮЯ"   // русский
        L"aeiouyAEIOUY";            // английский

    int count = 0;
    for (wchar_t c : str) {
        if (vowels.find(c) != std::wstring::npos) {
            ++count;
        }
    }
    return count;
}

int main() {
    // Переключаем stdin/stdout в UTF-16‑режим
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    std::wstring input;
    std::wcout << L"Введите строку: ";
    std::getline(std::wcin, input);

    int vowelCount = countVowels(input);
    std::wcout << L"Количество русских и английских гласных: "
        << vowelCount << L'\n';

    return 0;
}

