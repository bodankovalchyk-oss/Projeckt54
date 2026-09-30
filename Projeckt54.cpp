#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define N 256

/* Читає рядок з пробілами і прибирає '\n' */
void read_line(const char* prompt, char* s) {
    printf("%s", prompt);
    if (!fgets(s, N, stdin)) { s[0] = '\0'; return; }
    s[strcspn(s, "\n")] = '\0';
}

/* 4. Довжина рядка без strlen() */
int my_strlen(const char* s) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

/* 1. 'a' чи 'o' */
void task1(void) {
    char s[N];
    int a = 0, o = 0;
    read_line("Введіть рядок: ", s);
    for (int i = 0; s[i]; i++) {
        char c = tolower((unsigned char)s[i]);
        if (c == 'a') a++;
        else if (c == 'o') o++;
    }
    if (a > o)      printf("'a' більше (%d проти %d)\n", a, o);
    else if (o > a) printf("'o' більше (%d проти %d)\n", o, a);
    else            printf("Порівну: %d\n", a);
}

/* 2. Латинські букви, цифри, пробіли */
void task2(void) {
    char s[N];
    int letters = 0, digits = 0, spaces = 0;
    read_line("Введіть рядок: ", s);
    for (int i = 0; s[i]; i++) {
        unsigned char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) letters++;
        else if (c >= '0' && c <= '9') digits++;
        else if (c == ' ') spaces++;
    }
    printf("Букв: %d, цифр: %d, пробілів: %d\n", letters, digits, spaces);
}

/* 3. Поміняти регістр */
void task3(void) {
    char s[N];
    read_line("Введіть рядок: ", s);
    for (int i = 0; s[i]; i++) {
        unsigned char c = s[i];
        if (isupper(c))      s[i] = tolower(c);
        else if (islower(c)) s[i] = toupper(c);
    }
    printf("Результат: %s\n", s);
}

/* 4. Виклик my_strlen */
void task4(void) {
    char s[N];
    read_line("Введіть рядок: ", s);
    printf("Довжина: %d\n", my_strlen(s));
}

/* 5. Видалити заданий символ у новий рядок */
void task5(void) {
    char s[N], res[N], tmp[N];
    int j = 0;
    read_line("Введіть рядок: ", s);
    read_line("Який символ видалити: ", tmp);
    char ch = tmp[0];
    for (int i = 0; s[i]; i++)
        if (s[i] != ch)
            res[j++] = s[i];
    res[j] = '\0';
    printf("Результат: %s\n", res);
}

/* 6. Статистика рядка */
void task6(void) {
    char s[N];
    int ws = 0, vowels = 0, cons = 0, punct = 0;
    read_line("Введіть рядок (англ.): ", s);
    for (int i = 0; s[i]; i++) {
        unsigned char c = s[i];
        if (isspace(c)) ws++;
        else if (isalpha(c)) {
            if (strchr("aeiouAEIOU", c)) vowels++;
            else cons++;
        }
        else if (ispunct(c)) punct++;
    }
    printf("Пробільних: %d\nГолосних: %d\nПриголосних: %d\nЗнаків пунктуації: %d\n",
        ws, vowels, cons, punct);
}

int main(void) {
#ifdef _WIN32
    SetConsoleOutputCP(65001);  /* вивід у UTF-8 */
    SetConsoleCP(65001);        /* введення у UTF-8 */
#endif

    char choice[N];
    while (1) {
        printf("\n=== Меню ===\n"
            "1 - 'a' чи 'o'\n"
            "2 - букви / цифри / пробіли\n"
            "3 - змінити регістр\n"
            "4 - довжина без strlen\n"
            "5 - видалити символ\n"
            "6 - статистика рядка\n"
            "0 - вихід\n");
        read_line("Ваш вибір: ", choice);

        switch (choice[0]) {
        case '1': task1(); break;
        case '2': task2(); break;
        case '3': task3(); break;
        case '4': task4(); break;
        case '5': task5(); break;
        case '6': task6(); break;
        case '0': return 0;
        default:  printf("Невірний вибір\n");
        }
    }
}
