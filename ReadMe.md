# JSON-parser

Проектът представлява конзолно C++ приложение за зареждане, анализ, редактиране и съхранение на JSON файлове чрез команден интерфейс. Поддържа пълна работа с JSON структура: обекти, масиви, низове, числа, булеви стойности и `null`.

## 🧩 Основни компоненти
- **JsonReader** – парсира входен JSON поток и създава обектно дърво
- **JsonValue & наследници** – представят всички типове JSON стойности (обект, масив, низ и др.)
- **JsonVisitor** – реализира Visitor шаблон за обход
- **MyString** – собствен клас за управление на низове
- **Command Pattern** – позволява лесно добавяне и изпълнение на команди
- **CommandFactory** – създава команди по низов вход
- **JsonCommandProccesor** – отговаря за изпълнението на команди върху JSON структурата

## 📚 Поддържани команди
- `print` – отпечатва текущата JSON структура
- `validate` – проверява дали JSON структурата е валидна
- `set` – променя стойност по даден път
- `create` – създава нов елемент в JSON
- `delete` – изтрива елемент от JSON
- `move` – премества стойност от един път в друг
- `search` – търси по ключ в цялата структура
- `save` – записва текущия JSON във файла
- `saveas` – записва във файл с ново име

## ▶️ Начин на използване

```bash
./json-parser               # стартиране на програмата
```

След това програмата ще поиска път към JSON файл и ще приеме команди чрез конзолата:
```text
Enter JSON file path to load: data/example.json
> print
> validate
> set "path" "value"
> save
```

## 📄 Генериране на документация

Използвай `Doxygen` с включения `Doxyfile`:
```bash
doxygen Doxyfile
```

Отвори `https://vanchowe22.github.io/CourseProject/`, за да разгледаш документацията.

## 🛠️ Компилиране
Използвай компилатор като `g++`:
```bash
g++ main.cpp *.cpp -o json-parser
```

## 👨‍💻 Автори
- Аз
