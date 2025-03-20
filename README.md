# Kilo Editor

**Kilo** is a simple, lightweight terminal text editor written in C. It provides basic file editing capabilities along with features such as word search (with multiple match navigation) and syntax highlighting for C. Designed for quick editing directly from the terminal, Kilo is ideal for users who prefer a minimalistic yet powerful editing tool.

## Features

- **Basic Editing**: Open, modify, and save text files.
- **Search & Navigation**: Search for words and easily navigate through multiple matches.
- **Syntax Highlighting for C**: Built-in syntax highlighting for C source files, including highlighting of keywords, numbers, strings, and comments.
- **Terminal-based Interface**: Operates entirely in your terminal using ANSI escape sequences.
- **Customizable**: Configure behavior via macros (e.g., tab stop, quit confirmations) and easily extend its functionality.

## Installation & Usage
Compile the source code with `make`. 
Run the editor from the terminal with an optional filename:
```
./kilo [filename]
```
![image](https://github.com/user-attachments/assets/cd50473e-5b03-4ba4-aaf9-57e75b923bdf)

  

### Key Bindings

- **CTRL-S**: Save the current file.
- **CTRL-F**: Open the search prompt to find text.
- **CTRL-Q**: Quit the editor (if unsaved changes exist, press multiple times to force quit).
- **Arrow Keys**: Navigate through the document.
- **HOME/END**: Jump to the beginning or end of the current line.
- **PAGE UP/PAGE DOWN**: Scroll through the document.
- **BACKSPACE/DEL**: Delete characters.

## Acknowledgements
I'm deeply thankful for discovering this [tutorial](https://viewsourcecode.org/snaptoken/kilo/index.html) while I was searching for terminal documentation. It played a key role in helping me build the autocomplete feature for my Go project.
