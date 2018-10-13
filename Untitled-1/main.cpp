#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>

using namespace std;

void fill(vector <vector <int>> &arr, int N, int M)
{
    for (int i = 0; i < N; i++) {
        arr.push_back(vector<int>());
        for (int j = 0; j < M; j++) {
            arr[i].push_back(rand() % 100 + 1);
        }
    }
    cout << endl;
}

void fill(vector <vector <char>> &arr, int N, int M)
{
    for (int i = 0; i < N; i++) {
        arr.emplace_back();
        for (int j = 0; j < M; j++) {
            arr[i].push_back(arr[i][j] = ('a' + rand() % ('z' - 'a')));
        }
    }
}
template <typename T>
void display(vector <vector <T>> arr, int N, int M)
{
    for (int i = 0; i < N; i++) {
        if (i == 0) cout << endl;
        else cout << endl << endl;
        for (int j = 0; j < M; j++) {
            cout << arr[i][j] << '\t';
        }
    }
    cout << endl << endl;
}

template <typename T>
void sort(vector <vector <T>> &arr, int N, int M, int key)
{
    T temp;
    //Horizontal
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M - 1; k++) {
            for (int j = 0; j < M - k - 1; j++) {
                if (arr[i][j] - key < arr[i][j + 1] - key) {
                    swap(arr[i][j], arr[i][j + 1]);
                }
            }
        }
    }
    //Vertical
    for (int j = 0; j < M; j++) {
        for (int k = 0; k < N - 1; k++) {
            for (int i = 0; i < N - k - 1; i++) {
                if (arr[i][j] - key > arr[i + 1][j] - key) {
                    swap(arr[i][j], arr[i + 1][j]);
                }
            }
        }
    }
}


template <typename T>
void logic(vector <vector <T>> &arr, int N, int M, int key) {
    fill(arr, N, M);
    cout << "it was:" << endl;
    display(arr, N, M);
    sort(arr, N, M, key);
    cout << "it is:" << endl;
    display(arr, N, M);
}

void menu(short &n, int &N, int &M)
{
    srand(time(NULL));
    cout << "int/char?" << endl;
    cin >> n;
    while (n < 1 || n > 2) {
        cout << "another one!" << endl;
        cout << "int/char?" << endl;
        cin >> n;
    }

    cout << "Enter N & M" << endl;
    cin >> N >> M;
    while (N > 100 || N <= 0 || M > 50 || M <= 0) {
        cout << "another one!" << endl;
        cout << "Enter N & M" << endl;
        cin >> N >> M;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Лабораторная работа 8, Вариант 3, Данилов Дмитрий, ИКБО-02-17" << endl;
    cout << "Задание : 'Заполнить матрицу строковым или числовым типо данных и отсортировать по заданному значению'"
         << endl << endl;
    short n;
    int N, M;
    menu(n, N, M);
    switch (n) {
        case 1: {
            vector<vector<int>> arr;
            int key;
            cout << "Enter key:" << endl;
            string n;
            cin.get();
            getline(cin, n);
            while (!atoi(n.c_str())) {
                cout << "Try again!" << endl;
                cout << "Enter key:" << endl;
                getline(cin, n);
            }
            key = atoi(n.c_str());
            logic(arr, N, M, key);
            break;
        }
        case 2: {
            vector<vector<char>> arr(N, vector<char>(M));
            char key;
            cout << "Enter key:" << endl;
            cin >> key;
            while (isdigit(key)) {
                cout << "Try again!" << endl;
                cout << "Enter key:" << endl;
                cin >> key;
            }
            logic(arr, N, M, key);
            break;
        }
        default:
            break;
    }
    return 0;
}
