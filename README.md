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
   git clone https://github.com/your_username/task-manager.git
   ```

2. Navigate to the project directory:
  ```sh
  cd task-manager
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

This project is licensed under the MIT License
