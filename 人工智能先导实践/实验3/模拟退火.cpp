#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <vector>
using namespace std;

int SA_success_total_steps = 0;        // 模拟退火成功总步数
int SA_failed_total_steps = 0;        // 模拟退火失败总步数

class Board {
public:

    void fill_in_board() {
        initial();
        for (int i = 0; i < 8; ++i) {
            board[state[i]][i] = true;
        }
    }

    void initial() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                board[i][j] = false;
            }
        }
    }

    void random_initial_state() {
        for (int i = 0; i < 8; ++i) {
            state[i] = rand()% 8;
        }
    }

    void display(int mode) {
        //cout << endl << "-------------------------------------" << endl;
        cout << "当前状态信息: " << get_state() << endl
            << (mode == 0 ? "相互攻击的皇后对数: " : "不相互攻击的皇后对数: ") << (mode == 0 ? h_of_attack_pair() : h_of_not_attack_pair()) << endl
            << "(当不相互攻击的皇后对数达到28时，证明是可行解)" << endl
			<< "当前状态是可行解吗？" << (check(mode) ? "是！" : "不是！") << endl
            << "输出棋盘状态: " << endl;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

    }

    void set_state(string state_) {
        for (int i = 0; i < 8; ++i) {
            state[i] = state_[i] - '0';
        }
    }

    string get_state() {
        string res;
        for (int i = 0; i < 8; ++i) {
            res += state[i] + '0';
        }
        return res;
    }

    bool check(int mode) {
        if (mode == 0) return h_of_attack_pair() == 0;
        else return h_of_not_attack_pair() == 28;
    }

    int h_of_attack_pair() {
        int value = 0;
        for (int i = 0; i < 8; ++i) {
            value += count_attack(state[i], i);
        }
        return value / 2;
    }

    int h_of_not_attack_pair() {
        int value = 0;
        for (int i = 0; i < 8; ++i) {
            value += (7 - count_attack(state[i], i));
        }
        return value / 2;
    }

    int count_attack(int x, int y) {
        int count = 0;
        // 行
        for (int i = 0; i < 8; ++i) {
            if (i != y && board[x][i]) {
                count++;
            }
        }

        // 左上
        for (int i = x, j = y; i > 0 && j > 0; ) {
            if (board[--i][--j]) count++;
        }

        // 右下
        for (int i = x, j = y; i < 7 && j < 7; ) {
            if (board[++i][++j]) count++;
        }

        // 右上
        for (int i = x, j = y; i > 0 && j < 7; ) {
            if (board[--i][++j]) count++;
        }

        // 左下
        for (int i = x, j = y; i < 7 && j > 0; ) {
            if (board[++i][--j]) count++;
        }

        return count;
    }
    int h_value_board[8][8];
private:
    bool board[8][8];    // 棋盘
    int state[8];        // 状态的 8 位数串
};

Board b_tool;

float schedule(float T) {
    return 0.9999 * T;
}

// 模拟退火
bool Simulated_Annealing(Board* board, float(*p)(float)) {
    int steps = 0;
    double T = 5;        // 把初始温度设置为 5
    string old_state = board->get_state();
    string new_state = old_state;
    int old_value = 0;
    int new_value = 0;

    while (T > 0.00001) {
        ++steps;
        old_value = board->h_of_not_attack_pair();
        if (board->check(1)) {
            SA_success_total_steps += steps;
            return true;
        }
        T = (*p)(T);

        // 随机选择一个新的邻接状态
        // 随机抽取一个列
        int y = rand() % 8;
        int x = 0;
        // 随机抽取该列中的 free 的行（也即没有皇后的行）
        while (1) {
            x = rand() % 8;
            if (x != old_state[y] - '0') break;
        }
        new_state = old_state;
        new_state[y] = x + '0';

        board->set_state(new_state);
        board->fill_in_board();
        new_value = board->h_of_not_attack_pair();
        int deltaE = (new_value - old_value);

        if (deltaE > 0) {
            old_state = new_state;
        }
        else {
            if (((float)(rand() % 1000) / 1000) < exp(deltaE / T)) {
                old_state = new_state;
            }
            else {
                board->set_state(old_state);
                board->fill_in_board();
            }
        }
    }

    SA_failed_total_steps += steps;
    return false;
}

void SA_test() {
    Board board;
	for(int n_now=1;n_now<=3;n_now++){
		cout << "第" << n_now <<"次模拟退火："<< endl;
		board.random_initial_state();
		board.fill_in_board();
		board.display(1);
		Simulated_Annealing(&board, &schedule);
	    cout << "求解中..." ;
	    if (board.check(1)) {
	        cout << "求解成功！" << endl;
	    }
	    else cout << "求解失败！" << endl;
	    board.display(1);
	    cout << "-------------------------------------" << endl;  
	}
}

int main()
{
    srand(time(0));
    SA_test();
    return 0;
}
