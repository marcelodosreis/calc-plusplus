# calc-plusplus

**calc-plusplus** is a solution for interpreting and evaluating mathematical expressions, with support for advanced features. From basic operations to custom function creation, **calc-plusplus** provides an efficient and modular compiler that accurately processes complex expressions.

This project is built with the intent of delivering an extensible and organized tool, emphasizing programming best practices such as **Clean Code**, **Test-Driven Development (TDD)**, and **Domain-Driven Design (DDD)**. It is ideal for developers, students, and enthusiasts who want to understand and build simple yet robust compilers.

## Project Structure

The project follows a well-structured domain-driven design. Here is an overview of the folder structure:

```
├── src/                # Core logic of the project
│   ├── domain/         # Entities, Value Objects, Aggregates, etc.
│   ├── application/    # Use Cases, Services
│   ├── infrastructure/ # Concrete Implementations
│   └── presentation/   # User Input/Output (CLI, etc.)
├── tests/              # Unit and Integration Tests
├── build/              # Compiled binaries
├── scripts/            # Automation scripts (build, test, development)
│   ├── config/         # Configuration files for colors and messages
│   ├── build_and_test.sh  # Build and run unit tests script
│   └── develop.sh      # Development script to run the project
├── CMakeLists.txt      # CMake configuration file
└── README.md           # Project documentation
```

## Features

- **Mathematical Expression Parsing**: Handle basic operations like addition, subtraction, multiplication, and division, as well as more complex expressions.
- **Custom Function Creation**: Create and use custom functions within expressions.
- **Extensibility**: The system is designed to be extended with additional mathematical operations or custom behavior.
- **Test Coverage**: The project is fully tested with unit and integration tests ensuring reliability and stability.
- **CLI Interface**: User-friendly command-line interface for interacting with the compiler.

## Getting Started

To get started with **calc-plusplus**, follow the instructions below to build the project and run the necessary scripts.

### Prerequisites

Before starting, make sure you have the following installed:

- **CMake**: A cross-platform build system.
- **g++**: The GNU C++ compiler.
- **Make**: A tool to automate the build process.
- **Google Test**: For running unit tests.

### Building the Project

Run the following script to compile the project and run the unit tests:

```bash
./scripts/build_and_test.sh
```

This script will:

1. Build the project using **CMake** and **Make**.
2. Run the unit tests to ensure everything is working correctly.

### Running the Project

Once the project is built, you can run the compiled binary with the following script:

```bash
./scripts/develop.sh
```

This script will execute the project directly without requiring a build step, assuming the project has already been compiled.

### Manually Building and Running the Project

If you prefer to manually build and run the project, you can follow these steps:

1. **Build the project**:

   ```bash
   mkdir -p build
   cd build
   cmake ..
   make
   ```

2. **Run the project**:

   After the build is complete, you can run the compiled binary with:

   ```bash
   ./calc-plusplus
   ```

### Running Tests

To manually run the tests after building the project, use the following command:

```bash
ctest --output-on-failure  # Run tests and display output on failure
```

## Folder Structure

The following outlines the purpose of each main folder:

- **src/**: Contains the source code organized in subfolders:
  - **domain/**: Defines the core business logic entities (e.g., `Expression`, `Parser`, `Evaluator`).
  - **application/**: Handles the use cases (e.g., parsing and evaluating expressions).
  - **infrastructure/**: Concrete implementations such as file IO or external dependencies.
  - **presentation/**: Handles user input and output, such as CLI interaction.

- **tests/**: Contains unit and integration tests to ensure the functionality of each module.

- **build/**: This folder is created during the build process, containing the compiled binary and object files.

- **scripts/**: Contains helper scripts to automate tasks such as build and testing. Key scripts:
  - **build_and_test.sh**: Automates the build and unit test process.
  - **develop.sh**: Allows you to run the compiled code without building it.
  
- **config/**: Contains configuration files for customizing messages and colors in the scripts.

## Contributing

We welcome contributions! Here are some ways you can contribute to **calc-plusplus**:

- **Report Bugs**: If you find any bugs, please open an issue in the repository.
- **Submit Features**: If you have an idea for a new feature, feel free to open a pull request.
- **Improve Documentation**: If you spot any areas where the documentation can be improved, please submit a PR.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Thanks to **Google Test** for providing a robust framework for unit testing.
- Special thanks to **StackOverflow** for all the troubleshooting help during development.

## Final Words

Thank you for checking out **calc-plusplus**! We hope this project serves as an educational and useful tool for anyone looking to understand the inner workings of a mathematical expression compiler. Enjoy exploring and contributing!
