// leetcode 274 H-Index.cpp

class Solution {
public:
    int heapSize;

    void maintain(vector<int> & citations, int i) {

        int left = 2 * i + 1, right = 2 * i + 2, largest = 0;

        largest = left < heapSize && citations[left] > citations[i] ? left : i;
        largest = right < heapSize && citations[right] > citations[largest] ? right : largest;

        if (largest != i) {
            swap(citations[i], citations[largest]);
            maintain(citations, largest);
        }

        return;
    }

    int hIndex(vector<int>& citations) {

        int i, h = 0;
        heapSize = citations.size();

        for (i = heapSize / 2 - 1; i >= 0; i--) maintain(citations, i);

        while (heapSize && citations[0] >= h + 1) {
            swap(citations[0], citations[heapSize - 1]);
            heapSize--;
            maintain(citations, 0);
            h++;
        }

        return h;
    }
};
