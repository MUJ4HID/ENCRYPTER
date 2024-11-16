# C Encryption Tool with Anti-Debugging and Polymorphic Functions

## Overview

This project showcases advanced techniques in C for encrypting sensitive data, obfuscating code, and avoiding detection by antivirus programs or reverse engineering tools. The tool employs dynamic function names, runtime encryption, and anti-debugging measures to significantly complicate analysis and detection efforts. The encryption key is dynamically retrieved from an external file to ensure it's not exposed within the code.

## Key Features

- **Anti-Debugging**: Detects the presence of debuggers and prevents the program from executing if one is found.
- **Runtime Code Encryption**: Encrypts and decrypts sensitive data during runtime to avoid static analysis detection.
- **Polymorphic Functions**: Dynamically selects one of several obfuscated function names to avoid pattern recognition during static analysis.
- **External Key Management**: Retrieves the encryption key from an external file (`keyfile.txt`), hiding it from code inspection and analysis.

## Requirements

- **Operating System**: Windows
- **C Compiler**: GCC, MSVC, or any compatible C compiler
- **External File**: `keyfile.txt` must be created to hold the encryption key.

## Setup

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/MUJ4HID/ENCRYPTER.git
   cd ENCRYPTER
Create a keyfile.txt in the root directory and insert your desired encryption key inside it.

Compile the code using a C compiler:

bash
Copy code
gcc -o encryption_tool main.c
Run the compiled tool:

bash
Copy code
./encryption_tool
Usage
Upon execution, the tool will:

Check if a debugger is attached, terminating the process if one is found.
Encrypt and decrypt sensitive information dynamically at runtime.
Randomly select and execute one of several dynamically created functions to confuse reverse engineers.
Retrieve the encryption key from an external file (keyfile.txt) to ensure it's not exposed in the code itself.
