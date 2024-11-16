#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// Anti-Debugging Technique: Detects if a debugger is present
int isDebuggerPresent() {
    __try {
        __asm {
            int 3  // Trigger a Debugger Interrupt
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return 0;  // No debugger, exception thrown
    }
    return 1;  // A debugger was detected
}

// Function Obfuscation: Dynamically generated function names
void obfuscateFunction(char *data, size_t size, const char *key, size_t key_size) {
    for (size_t i = 0; i < size; i++) {
        data[i] = data[i] ^ key[i % key_size];  // XOR-based encryption
    }
}

// Function to encrypt and decrypt sensitive code during runtime
void encryptCodeAtRuntime() {
    char secret_code[] = "Sensitive Information!";
    size_t size = strlen(secret_code);
    char encryption_key[] = "SecureKey";

    printf("Original Code: %s\n", secret_code);

    // Encrypt the code
    obfuscateFunction(secret_code, size, encryption_key, strlen(encryption_key));

    printf("Encrypted Code: %s\n", secret_code);

    // Decrypt the code
    obfuscateFunction(secret_code, size, encryption_key, strlen(encryption_key));

    printf("Decrypted Code: %s\n", secret_code);
}

// Polymorphic Function Creation: Dynamically generated function names
void createDynamicFunction() {
    srand(time(NULL));

    // Randomly select obfuscated function names
    const char *obfuscated_function_name[] = {
        "A3RjK9z", "X2HfB1L", "T7YdQ4Z", "P5VsN0M"
    };

    int random_index = rand() % 4;
    const char *selected_function = obfuscated_function_name[random_index];

    printf("Selected Dynamic Function: %s\n", selected_function);

    // Execute logic based on selected function
    if (strcmp(selected_function, "A3RjK9z") == 0) {
        printf("Executing function A3RjK9z\n");
    } else if (strcmp(selected_function, "X2HfB1L") == 0) {
        printf("Executing function X2HfB1L\n");
    } else if (strcmp(selected_function, "T7YdQ4Z") == 0) {
        printf("Executing function T7YdQ4Z\n");
    } else {
        printf("Executing function P5VsN0M\n");
    }
}

// Function to retrieve the encryption key from an external source (file)
char* getEncryptionKey() {
    FILE *file = fopen("keyfile.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to read the encryption key\n");
        exit(1);
    }

    char *key = malloc(256);
    fgets(key, 256, file);
    fclose(file);

    return key;
}

int main() {
    // Anti-Debugging Check
    if (isDebuggerPresent()) {
        printf("Debugger detected, exiting...\n");
        return 1;  // Exit if a debugger is detected
    }

    // Encrypting code at runtime
    encryptCodeAtRuntime();

    // Polymorphic function selection and execution
    createDynamicFunction();

    // Retrieving the encryption key from an external source
    char *key = getEncryptionKey();
    printf("Encryption key retrieved: %s\n", key);
    free(key);

    return 0;
}
