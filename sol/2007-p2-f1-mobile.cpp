#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Mobile {
    int id;
    int parentId;
    int count;
    vector<int> children;
};

int countPieces(vector<Mobile>& mobiles, int id, map<int, int>& pieceCount) {
    if (pieceCount.find(id) != pieceCount.end()) {
        return pieceCount[id];
    }

    Mobile& mobile = mobiles[id-1];
    int count = mobile.count;
    for (int child : mobile.children) {
        count += countPieces(mobiles, child, pieceCount);
    }
    pieceCount[id] = count;
    return count;
}

bool isBalanced(vector<Mobile>& mobiles) {
    map<int, int> pieceCount;
    for (Mobile& mobile : mobiles) {
        int count = countPieces(mobiles, mobile.id, pieceCount);
        for (int child : mobile.children) {
            if (countPieces(mobiles, child, pieceCount) != count) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<Mobile> mobiles(N);
    for (int i = 0; i < N; i++) {
        int id, parentId;
        cin >> id >> parentId;
        mobiles[id-1].id = id;
        mobiles[id-1].parentId = parentId;
        if (parentId != 0) {
            mobiles[parentId-1].children.push_back(id);
        }
    }

    for (int i = 0; i < N; i++) {
        mobiles[i].count = 1;
    }

    cout << (isBalanced(mobiles) ? "bem" : "mal") << endl;

    return 0;
}