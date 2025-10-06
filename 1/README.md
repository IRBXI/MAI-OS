# MAI-OS-1

Вариант - 5

[Документ со всеми вариантами](https://cloud.mail.ru/public/BurB/oPQiVk7Vc/%D0%9B%D0%A0/lab_work_1_v4.pdf)

## Структура проекта

- `lib/` - исходный код библиотек
- `CMakeLists.txt` - конфигурация CMake

## Сборка и запуск

```bash
# Создание директории для сборки
mkdir build
cd build

# Конфигурация CMake
cmake ..

# Сборка проекта
make

# Запуск родительского процесса 
./parent
