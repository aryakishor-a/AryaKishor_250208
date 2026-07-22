#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <windows.h>
using namespace std;
// ---- Settings you can change ----
const int DELAY_MS = 400; // speed of animation (smaller = faster)
const char BAR_CHAR = '#'; // character used to draw each bar
// Clears the console screen (works on Windows, Linux, Mac)
void clearScreen() {
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif
}
// Draws the array as horizontal bars.
// compareIndex1 / compareIndex2 mark the two bars currently being compared
// (they are shown in a different color). Pass -1 if not applicable.
void drawArray(const vector<int>& arr, int compareIndex1 = -1, int compareIndex2 = -1) {
clearScreen();
cout << "----- DSA Visualizer: Bubble Sort -----\n\n";
for (int i = 0; i < (int)arr.size(); i++) {
cout << "Index " << i << " [" << arr[i] << "]\t";
// Choose color: red for elements being compared, green otherwise
if (i == compareIndex1 || i == compareIndex2) {
cout << "\033[1;31m"; // red
} else {
cout << "\033[1;32m"; // green
}
for (int j = 0; j < arr[i]; j++) {
cout << BAR_CHAR;
}
cout << "\033[0m" << "\n"; // reset color
}
cout << "\n";
Sleep(DELAY_MS);
}

void drawSelectionArray(const vector<int>& arr, int compareIndex1 = -1, int compareIndex2 = -1) {
clearScreen();
cout << "----- DSA Visualizer: Selection Sort -----\n\n";
for (int i = 0; i < (int)arr.size(); i++) {
cout << "Index " << i << " [" << arr[i] << "]\t";
// Choose color: red for elements being compared, green otherwise
if (i == compareIndex1 || i == compareIndex2) {
cout << "\033[1;31m"; // red
} else {
cout << "\033[1;32m"; // green
}
for (int j = 0; j < arr[i]; j++) {
cout << BAR_CHAR;
}
cout << "\033[0m" << "\n"; // reset color
}
cout << "\n";
Sleep(DELAY_MS);
}
// Bubble sort, redrawing the array at every comparison and every swap
void bubbleSortVisual(vector<int>& arr) {
int n = arr.size();
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
// Show which two bars are being compared right now
drawArray(arr, j, j + 1);
if (arr[j] > arr[j + 1]) {
swap(arr[j], arr[j + 1]);
// Show the array again after the swap
drawArray(arr, j, j + 1);
}
}
}
drawArray(arr); // final, fully sorted state
}

// I added a selection sort as well.
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    drawSelectionArray(arr);
    for (int i = 0; i < n - 1; i++) {
        int minimumIndex = i;
        for (int j = i + 1; j < n; j++) {
            drawSelectionArray(arr, minimumIndex, j);
            if (arr[j] < arr[minimumIndex]) {
                minimumIndex = j;
                drawSelectionArray(arr, i, minimumIndex);
            }
        }
        if (minimumIndex != i) {
            swap(arr[i], arr[minimumIndex]);
            drawSelectionArray(arr, i, minimumIndex);
        }
    }

    drawSelectionArray(arr);
    cout << "\nSelection Sort completed!\n";
}
int main() {
vector<int> arr;
int n;

cout << "How many numbers do you want to visualize? ";
cin >> n;
cout << "Enter " << n << " numbers, one by one (try values between 1 and 20):\n";
for (int i = 0; i < n; i++) {
int val;
cin >> val;
arr.push_back(val);
}
int choice;
cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSortVisual(arr);
            cout << "\nBubble Sort completed!\n";
            break;

        case 2:
            selectionSort(arr);
            break;

        default:
            cout << "Invalid choice!\n";
            break;
    }

    return 0;
}