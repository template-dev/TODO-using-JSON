# English

# Task Manager

This is a simple TODO application developed in C++ that allows users to manage their tasks. Tasks are stored in a JSON file.

## Features

- Add tasks
- Remove tasks
- Edit tasks
- Print all tasks
- Set task status

## Requirements

- C++ compiler supporting C++11 or later
- CMake

## Installation

1. Clone the repository:
  ```sh
  git clone https://github.com/template-dev/TODO-using-JSON.git
  ```

2. Navigate to the project directory:
  ```sh
  cd TODO-using-JSON
  ```

3. Create a build directory:
  ```sh
  mkdir build
  ```

4. Navigate to the build directory:
  ```sh
  cd build
  ```

5. Generate the build files with CMake:
  ```sh
  cmake ..
  ```

6. Compile the project:
  ```sh
  cmake --build .
  ```

## Usage

- Run the executable generated after compilation.
- You will be presented with a menu allowing you to perform various tasks such as adding, removing, editing, printing, and setting task statuses.
- Follow the prompts to interact with the application.

## Dependencies

- [nlohmann/json](https://github.com/nlohmann/json): A C++ library for JSON manipulation, used for storing tasks in JSON format.

## JSON File Structure

Tasks are stored in a JSON file with the following structure:

  ```json
  [
    {
      "title": "Task Title",
      "description": "Task Description",
      "completed": false
    },
    {
      "title": "Another Task",
      "description": "Description of another task",
      "completed": false
    }
  ]
  ```

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please follow these steps:

- Fork the repository.
- Create a new branch (git checkout -b feature/improvement)
- Make your changes.
- Commit your changes (git commit -am 'Add new feature')
- Push to the branch (git push origin feature/improvement)
- Create a new Pull Request.

## License

This project is licensed under the MIT License.

---

# Русский

# Менеджер задач

Это простое приложение TODO, разработанное на C++, позволяющее пользователям управлять своими задачами. Задачи хранятся в JSON-файле.

## Возможности

- Добавление задач
- Удаление задач
- Редактирование задач
- Вывод всех задач
- Установка статуса задачи

## Требования

- Компилятор C++, поддерживающий C++11 или более поздние версии
- CMake

## Установка

1. Клонировать репозиторий:
  ```sh
  git clone https://github.com/template-dev/TODO-using-JSON.git
  ```

2. Перейти в директорию проекта:
  ```sh
  cd TODO-using-JSON
  ```

3. Создать директорию для сборки:
  ```sh
  mkdir build
  ```

4. Перейти в директорию сборки:
  ```sh
  cd build
  ```

5. Сгенерировать файлы сборки с помощью CMake:
  ```sh
  cmake ..
  ```

6. Скомпилировать проект:
  ```sh
  cmake --build .
  ```

## Использование
- Запустите исполняемый файл, сгенерированный после компиляции.
- Вы увидите меню, позволяющее выполнять различные задачи, такие как добавление, удаление, редактирование, вывод и установка статуса задачи.
- Следуйте подсказкам, чтобы взаимодействовать с приложением.

## Зависимости

- [nlohmann/json](https://github.com/nlohmann/json): библиотека для работы с JSON в C++, используется для хранения задач в формате JSON.

## Структура JSON-файла

Задачи хранятся в JSON-файле со следующей структурой:

  ```json
  [
    {
      "title": "Task Title",
      "description": "Task Description",
      "completed": false
    },
    {
      "title": "Another Task",
      "description": "Description of another task",
      "completed": false
    }
  ]
  ```

## Вклад

Приветствуются вклады! Если вы хотите внести свой вклад в этот проект, пожалуйста, выполните следующие шаги:

- Форкните репозиторий.
- Создайте новую ветку (git checkout -b feature/improvement)
- Внесите изменения.
- Зафиксируйте изменения (git commit -am 'Добавить новую функцию')
- Отправьте изменения в ветку (git push origin feature/improvement)
- Создайте новый Pull Request.

## Лицензия

Этот проект распространяется под лицензией MIT.
