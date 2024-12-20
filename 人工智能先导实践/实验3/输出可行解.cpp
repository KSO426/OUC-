#include <bits/stdc++.h>
using namespace std;

// ȫ�ֱ��������ڼ�¼�������
int sum = 0;

/**
 *  �������Ϸ���һ���ʺ󣬲���ǲ��ܷ��ûʺ��λ��
 * 
 * param x �ʺ��������
 * param y �ʺ��������
 * param cant_put ��ά��������ʾ��������Щλ�ò��ܷ��ûʺ�1��ʾ���ܷ��ã�0��ʾ���Է��ã�
 */
void PutQueen(int x, int y, vector<vector<int> > &cant_put) {
    // 8�������ƫ����
    int dot_x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dot_y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    // ��ǵ�ǰλ�ò��ܷ��ûʺ�
    cant_put[x][y] = 1;

    // ��ǻʺ�����λ�õ����й�����Χ
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
 * param n ���̵Ĵ�С��N x N��
 * param q ��ǰ���ڴ������
 * param cant_put ��ά��������ʾ��������Щλ�ò��ܷ��ûʺ�1��ʾ���ܷ��ã�0��ʾ���Է��ã�
 * param now_rank ��ǰ�����̲��֣����ַ�����ʾ
 * param all_rank ���е���Ч��
 */
void n_queen(int n, int q, vector<vector<int> > &cant_put, vector<string> &now_rank, vector<vector<string> > &all_rank) {
    // ����Ѿ������������У���¼��ǰ��
    if (q == n) {
        all_rank.push_back(now_rank);
        sum += 1;
        return;
    }

    // �����ڵ�ǰ�е�ÿһ�з��ûʺ�
    for (int i = 0; i < n; i++) {
        if (cant_put[q][i] == 0) {
            // ���浱ǰ�Ĳ��ܷ��ûʺ��λ��
            vector<vector<int> > history_cant_put = cant_put;

            // ���ûʺ�
            now_rank[q][i] = 'Q';
            PutQueen(q, i, cant_put);

            // �ݹ鴦����һ��
            n_queen(n, q + 1, cant_put, now_rank, all_rank);

            // ���ݣ��ָ�֮ǰ�Ĳ��ܷ��ûʺ��λ��
            cant_put = history_cant_put;
            now_rank[q][i] = '.';
        }
    }
}

int main() {
    int n;
    cin >> n; 
    // ��ʼ����ǰ�����̲���
    vector<string> now_rank(n);
    for (int i = 0; i < n; i++) {
        now_rank[i] = string(n, '.');
    }

    // �洢���е���Ч��
    vector<vector<string> > all_rank;

    // ��ʼ�����ܷ��ûʺ��λ��
    vector<vector<int> > cant_put(n, vector<int>(n, 0));

    // ��ʼ���N�ʺ�����
    n_queen(n, 0, cant_put, now_rank, all_rank);

    // ������е���Ч��
    for (int i = 0; i < all_rank.size(); i++) {
        for (int j = 0; j < n; j++) {
            cout << all_rank[i][j] << endl;
        }
        cout << "-------------------------------------------------------------" << endl;
    }

    // ����������
    cout <<  "n=" << n <<"ʱ���н⹲"<< sum << "����������ʾ��";

    return 0;
}


