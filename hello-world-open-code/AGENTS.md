# AGENTS.md - Coding Guidelines for Interesting C Programs Repository

This document provides coding guidelines, build commands, and conventions for agentic coding assistants working in this C programming repository.

## Project Structure

Each C program project follows this standard directory structure:
```
project-name/
├── src/          # Source files (.c)
├── include/      # Header files (.h)
├── obj/          # Object files (generated)
├── bin/          # Executables (generated)
├── Makefile      # Build configuration
└── .gitignore    # Git ignore rules
```

## Build Commands

### Standard Build Targets
- `make` or `make all` - Build the project executable
- `make run` - Build and execute the program
- `make release` - Build optimized release version
- `make clean` - Remove generated files
- `make submit` - Create submission zip file

### Build Configuration
- Compiler: `gcc`
- Debug flags: `-g -Wall`
- Release flags: `-Wall -O2 -DNDEBUG`
- Project name derived from directory name

### Running Individual Tests
This repository contains example programs rather than unit tests. To run a specific program:
```bash
cd path/to/project
make run
```

For debugging individual components, use gdb:
```bash
gdb bin/project-name
```

## Code Style Guidelines

### File Organization
- **Source files**: Place in `src/` directory
- **Headers**: Place in `include/` directory with corresponding .c files
- **Main function**: Always in `src/main.c`
- **Library functions**: Split across multiple .c/.h pairs in src/include

### Header Files
- Use include guards: `#ifndef __FILENAME_H_` and `#define __FILENAME_H_`
- Include system headers first, then local headers
- Declare all public functions and types
- End with `#endif // !__FILENAME_H_`

Example:
```c
#ifndef __HELLO_H_
#define __HELLO_H_

#include <stdio.h>

void hello();

#endif // !__HELLO_H_
```

### Source Files
- Include corresponding header first
- Then system headers
- Use relative paths: `#include "../include/filename.h"`

### Naming Conventions

#### Functions
- Use lowercase with underscores: `function_name()`
- Start with action verb when appropriate: `init_ui()`, `show_matrix()`
- Boolean functions: `is_valid()`, `has_error()`

#### Variables
- Lowercase with underscores: `user_input`, `file_count`
- Constants: `UPPERCASE_WITH_UNDERSCORES`
- Pointers: `ptr_name` or `p_name`

#### Types and Structs
- Structs: `struct StructName { ... };`
- Typedefs: `typedef struct StructName StructName;`
- Enums: `enum EnumName { VALUE_ONE, VALUE_TWO };`

#### Files
- Headers: `filename.h`
- Sources: `filename.c`
- Use descriptive names matching main functionality

### Code Formatting

#### Indentation
- Use consistent indentation (4 spaces recommended)
- Function braces on same line as function declaration
- Control structure braces on new lines

#### Spacing
- Space after keywords: `if (condition)`
- No space in function calls: `function(arg1, arg2)`
- Space around operators: `a + b`, `x == y`
- No trailing whitespace

#### Line Length
- Keep lines under 80 characters when possible
- Break long lines logically at operators or commas

### Function Definitions

#### Main Function
```c
int main(int argc, char *argv[]) {
    // implementation
    return EXIT_SUCCESS;
}
```

#### Regular Functions
```c
void function_name(int param1, char *param2) {
    // implementation
    return;  // explicit return for void functions
}
```

### Error Handling
- Use `EXIT_SUCCESS` and `EXIT_FAILURE` for main return values
- Check return values from system calls
- Handle NULL pointer returns from malloc/calloc
- Use perror() or fprintf(stderr, ...) for error messages

Example:
```c
FILE *file = fopen("filename.txt", "r");
if (file == NULL) {
    perror("Failed to open file");
    return EXIT_FAILURE;
}
```

### Memory Management
- Always free allocated memory
- Use `sizeof()` with malloc/calloc
- Check allocation success
- Set pointers to NULL after freeing

### Includes and Dependencies
- System headers first: `<stdio.h>`, `<stdlib.h>`, etc.
- Local headers second: `"../include/header.h"`
- Minimize includes in headers (forward declarations when possible)
- Include what you use directly

### Comments
- Use `/* */` for multi-line comments
- Use `//` for single-line comments
- Comment complex logic and algorithms
- Document function purposes in headers
- Avoid obvious comments

### Constants and Macros
- Use `#define` for constants
- Place defines at top of files or in headers
- Use meaningful names
- Consider `const` variables for typed constants

### Best Practices

#### Portability
- Use standard C features (C99 minimum)
- Avoid platform-specific code unless necessary
- Test on multiple compilers if possible

#### Performance
- Use appropriate data structures
- Minimize memory allocations in loops
- Profile before optimizing

#### Security
- Validate input parameters
- Use safe string functions when available
- Avoid buffer overflows
- Sanitize user input

#### Maintainability
- Write self-documenting code
- Use consistent naming
- Keep functions focused on single responsibility
- Document complex algorithms

### Makefile Conventions

#### Standard Variables
- `CC = gcc` - Compiler
- `CFLAGS` - Compiler flags
- `SRC_DIR = src` - Source directory
- `INCLUDE_DIR = include` - Include directory
- `OBJ_DIR = obj` - Object directory
- `BIN_DIR = bin` - Binary directory

#### Pattern Rules
```makefile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
    $(CC) $(CFLAGS) -c $< -o $@
```

### Git Workflow
- Use descriptive commit messages
- Commit related changes together
- Use .gitignore to exclude generated files (obj/, bin/)
- Keep repository clean of build artifacts

### Debugging
- Use `-g` flag for debug builds
- Use gdb for debugging: `gdb bin/program`
- Add debug prints with `fprintf(stderr, ...)`
- Remove debug code before release

### Code Review Checklist
- [ ] Compiles without warnings
- [ ] Follows naming conventions
- [ ] Includes proper error handling
- [ ] Memory properly managed
- [ ] Code formatted consistently
- [ ] Functions have single responsibility
- [ ] Comments added for complex logic
- [ ] No hardcoded values (use constants)
- [ ] Input validation implemented
- [ ] Tested with edge cases

This document should be updated as coding standards evolve in the repository.