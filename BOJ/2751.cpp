#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int score[1000005];
int heapSize;

void constructHeap(int arr[], int n);
void fixHeap(int heap[], int K);

void acceleratedHeapSort(int heap[], int n);
void deleteMax(int heap[]);
void fixHeapFast(int heap[], int n, int K, int vacant, int h);
void bubbleUpHeap(int heap[], int root, int K, int vacant);
int promote(int heap[], int hStop, int vacant, int h);
bool haveLchild(int idx, int size);
bool haveRchild(int idx, int size);

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    heapSize = N;
    for (int i = 1; i <= N; i++)
        cin >> score[i];

    constructHeap(score, N);
    acceleratedHeapSort(score, N);
    for (int i = 1; i <= N; i++)
        cout << score[i] << '\n';
}

void constructHeap(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--)
        fixHeap(arr, i);
}

void fixHeap(int heap[], int K) {
    if (!haveLchild(K, heapSize) && !haveRchild(K, heapSize)) return;
    else if (!haveRchild(K, heapSize)) {
        int lchild = 2 * K;
        if (heap[K] >= heap[lchild]) return;
        else {
            int temp = heap[K];
            heap[K] = heap[lchild];
            heap[lchild] = temp;
            return;
        }
    }
    else {
        int lchild = 2 * K;
        int rchild = 2 * K + 1;
        int largerChild;
        if (heap[lchild] >= heap[rchild]) largerChild = lchild;
        else largerChild = rchild;

        if (heap[K] >= heap[largerChild]) return;
        else {
            int temp = heap[K];
            heap[K] = heap[largerChild];
            heap[largerChild] = temp;
            fixHeap(heap, largerChild);
        }
    }
}

void acceleratedHeapSort(int heap[], int n) {
    for (int i = n; i >= 1; i--) {
        int curMax = heap[1];
        deleteMax(heap);
        heap[i] = curMax;
    }
}

void deleteMax(int heap[]) {
    int K = heap[heapSize];
    heapSize--;
    fixHeapFast(heap, heapSize, K, 1, (int)log2(heapSize));
}

void fixHeapFast(int heap[], int n, int K, int vacant, int h) {
    if (h <= 1) {
        if (!haveLchild(vacant, n) && !haveRchild(vacant, n)) {
            heap[vacant] = K;
        }
        else if (!haveRchild(vacant, n)) {
            int lchild = 2 * vacant;
            if (K >= heap[lchild]) heap[vacant] = K;
            else {
                heap[vacant] = heap[lchild];
                heap[lchild] = K;
            }
        }
        else {
            int lchild = 2 * vacant;
            int rchild = 2 * vacant + 1;
            int largerChild;
            if (heap[lchild] >= heap[rchild]) largerChild = lchild;
            else largerChild = rchild;

            if (K >= heap[largerChild]) heap[vacant] = K;
            else {
                heap[vacant] = heap[largerChild];
                heap[largerChild] = K;
            }
        }
    }
    else {
        int hStop = (h + 1) / 2;
        int vacStop = promote(heap, hStop, vacant, h);
        int vacParent = vacStop / 2;
        if (heap[vacParent] <= K) {
            heap[vacStop] = heap[vacParent];
            bubbleUpHeap(heap, vacant, K, vacParent);
        }
        else
            fixHeapFast(heap, n, K, vacStop, hStop);
    }
}

void bubbleUpHeap(int heap[], int root, int K, int vacant) {
    if (vacant == root)
        heap[vacant] = K;
    else {
        int parent = vacant / 2;
        if (K <= heap[parent])
            heap[vacant] = K;
        else {
            heap[vacant] = heap[parent];
            bubbleUpHeap(heap, root, K, parent);
        }
    }
}

int promote(int heap[], int hStop, int vacant, int h) {
    int vacStop;
    if (h <= hStop) vacStop = vacant;
    else if (heap[2 * vacant] <= heap[2 * vacant + 1]) {
        heap[vacant] = heap[2 * vacant + 1];
        vacStop = promote(heap, hStop, 2 * vacant + 1, h - 1);
    }
    else {
        heap[vacant] = heap[2 * vacant];
        vacStop = promote(heap, hStop, 2 * vacant, h - 1);
    }
    return vacStop;
}

bool haveLchild(int idx, int size) {
    if (idx * 2 > size) return false;
    else return true;
}

bool haveRchild(int idx, int size) {
    if (idx * 2 + 1 > size) return false;
    else return true;
}