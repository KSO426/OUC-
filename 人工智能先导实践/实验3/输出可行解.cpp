#include <bits/stdc++.h>
using namespace std;

// 全局变量，用于记录解的数量
int sum = 0;

/**
 *  在棋盘上放置一个皇后，并标记不能放置皇后的位置
 * 
 * param x 皇后的行坐标
 * param y 皇后的列坐标
 * param cant_put 二维向量，表示棋盘上哪些位置不能放置皇后（1表示不能放置，0表示可以放置）
 */
void PutQueen(int x, int y, vector<vector<int> > &cant_put) {
    // 8个方向的偏移量
    int dot_x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dot_y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    // 标记当前位置不能放置皇后
    cant_put[x][y] = 1;

    // 标记皇后所在位置的所有攻击范围
    for (int i = 1; i < cant_put.size(); i++) {
        for (int j = 0; j < 8; j++) {
            int node_x = x + i * dot_x[j];
            int node_y = y + i * dot_y[j];
            if (node_x >= 0 && node_x < cant_put.size() && node_y >= 0 && node_y < cant_put.size()) {
                cant_put[node_x][node_y] = 1;
            }
        }
    }
}

/**
 * 
 * param n 棋盘的大小（N x N）
 * param q 当前正在处理的行
 * param cant_put 二维向量，表示棋盘上哪些位置不能放置皇后（1表示不能放置，0表示可以放置）
 * param now_rank 当前的棋盘布局，用字符串表示
 * param all_rank 所有的有效解
 */
void n_queen(int n, int q, vector<vector<int> > &cant_put, vector<string> &now_rank, vector<vector<string> > &all_rank) {
    // 如果已经处理完所有行，记录当前解
    if (q == n) {
        all_rank.push_back(now_rank);
        sum += 1;
        return;
    }

    // 尝试在当前行的每一列放置皇后
    for (int i = 0; i < n; i++) {
        if (cant_put[q][i] == 0) {
            // 保存当前的不能放置皇后的位置
            vector<vector<int> > history_cant_put = cant_put;

            // 放置皇后
            now_rank[q][i] = 'Q';
            PutQueen(q, i, cant_put);

            // 递归处理下一行
            n_queen(n, q + 1, cant_put, now_rank, all_rank);

            // 回溯，恢复之前的不能放置皇后的位置
            cant_put = history_cant_put;
            now_rank[q][i] = '.';
        }
    }
}

int main() {
    int n;
    cin >> n; 
    // 初始化当前的棋盘布局
    vector<string> now_rank(n);
    for (int i = 0; i < n; i++) {
        now_rank[i] = string(n, '.');
    }

    // 存储所有的有效解
    vector<vector<string> > all_rank;

    // 初始化不能放置皇后的位置
    vector<vector<int> > cant_put(n, vector<int>(n, 0));

    // 开始求解N皇后问题
    n_queen(n, 0, cant_put, now_rank, all_rank);

    // 输出所有的有效解
    for (int i = 0; i < all_rank.size(); i++) {
        for (int j = 0; j < n; j++) {
            cout << all_rank[i][j] << endl;
        }
        cout << "-------------------------------------------------------------" << endl;
    }

    // 输出解的数量
    cout <<  "n=" << n <<"时可行解共"<< sum << "个，如上所示。";

    return 0;
}


