#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'connectingTowns' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY routes
 */

int connectingTowns(int n, int routes_count, int* routes) {
    if (n == 2) {
        return routes[0];
    } else {
        return routes[0] * connectingTowns(n - 1, routes_count - 1, routes + 1) % 1234567;
    }
}


int main()
{
    FILE* input_file = fopen("input5.txt", "r");
    FILE* output_file = fopen("output5.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error al abrir el archivo de entrada o de salida.\n");
        return 1;
    }

    int t;
    fscanf(input_file, "%d", &t);

    int n;
    char** routes_temp;
    int* routes;

    int t_itr;  

    for (t_itr = 0; t_itr < t; t_itr++) {  
        fscanf(input_file, "%d", &n);
        fgetc(input_file); 
        char input_buffer[1024];
        fgets(input_buffer, sizeof(input_buffer), input_file);
        routes_temp = split_string(rtrim(input_buffer));

        routes = (int*)malloc((n - 1) * sizeof(int));
		
		int i;
        for (i = 0; i < n - 1; i++) {
            int routes_item = parse_int(*(routes_temp + i));
            *(routes + i) = routes_item;
        }

        int result = connectingTowns(n, n - 1, routes);

        fprintf(output_file, "%d\n", result);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}





char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = (char*)realloc(data, alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = (char*)realloc(data, alloc_length);


        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = (char*)realloc(data, alloc_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = (char*)realloc(data, alloc_length);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = (char**)realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
