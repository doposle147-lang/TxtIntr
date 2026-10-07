#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void print_help(const char* prog) {
    cout << "Использование: " << prog << " -o <операция> ЧИСЛО1 ЧИСЛО2 ЧИСЛО3 [ЧИСЛО4 [ЧИСЛО5]]" << endl;
    cout << endl;
    cout << "Аддитивный калькулятор (вариант 2)." << endl;
    cout << "Выполняет одну операцию над набором от 3 до 5 операндов." << endl;
    cout << endl;
    cout << "Параметры:" << endl;
    cout << "  -o, --operation summa      суммирование всех операндов" << endl;
    cout << "  -o, --operation subtract   вычитание из первого операнда всех остальных" << endl;
    cout << "  -h, --help                 показать справку" << endl;
    cout << endl;
    cout << "Примеры:" << endl;
    cout << "  " << prog << " -o summa 1 2 3 4 5" << endl;
    cout << "  " << prog << " --operation subtract 10 2 3" << endl;
}

int main(int argc, char* argv[]) {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    if (argc == 1) {
        print_help(argv[0]);
        return 0;
    }

    const char* op = nullptr;
    double nums[10];
    int count = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help(argv[0]);
            return 0;
        } else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--operation") == 0) {
            if (i + 1 >= argc) {
                cerr << "Ошибка: после " << argv[i] << " должно быть имя операции" << endl;
                return 1;
            }
            op = argv[++i];
        } else {
            char* end = nullptr;
            double v = strtod(argv[i], &end);
            if (end == argv[i] || *end != '\0') {
                cerr << "Ошибка: '" << argv[i] << "' не является числом" << endl;
                return 1;
            }
            nums[count++] = v;
        }
    }

    if (op == nullptr) {
        cerr << "Ошибка: не указана операция (-o или --operation)" << endl;
        print_help(argv[0]);
        return 1;
    }

    if (strcmp(op, "summa") != 0 && strcmp(op, "subtract") != 0) {
        cerr << "Ошибка: неизвестная операция '" << op << "'" << endl;
        cerr << "Допустимые операции: summa, subtract" << endl;
        return 1;
    }

    if (count < 3 || count > 5) {
        cerr << "Ошибка: операндов должно быть от 3 до 5 (получено " << count << ")" << endl;
        return 1;
    }

    double res;
    if (strcmp(op, "summa") == 0) {
        res = 0;
        for (int i = 0; i < count; i++) res += nums[i];
        for (int i = 0; i < count; i++) {
            if (i > 0) cout << " + ";
            cout << nums[i];
        }
    } else {
        res = nums[0];
        for (int i = 1; i < count; i++) res -= nums[i];
        for (int i = 0; i < count; i++) {
            if (i > 0) cout << " - ";
            cout << nums[i];
        }
    }

    cout << " = " << res << endl;
    return 0;
}
