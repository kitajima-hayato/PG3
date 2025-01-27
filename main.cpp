#include <iostream>
#include <string>
#include <chrono>

using namespace std;
int main() {
    // 100,000文字のstd::stringを初期化
    string original(100000, 'a');

    // コピー操作の時間を計測
    auto start_copy = chrono::system_clock::now(); // 開始時刻を保存
    string copied = original; // コピー
    auto end_copy = chrono::system_clock::now();  // 終了時刻を保存
    auto dur_copy = end_copy - start_copy; // 要した時間を計算
    auto msec_copy = chrono::duration_cast<chrono::microseconds>(dur_copy).count(); // コピー操作の時間を計測

    // 移動操作の時間を計測
    auto start_move = chrono::system_clock::now(); // 開始時刻を保存
    string moved = std::move(original); // 移動
    auto end_move = chrono::system_clock::now();  // 終了時刻を保存
    auto dur_move = end_move - start_move; // 要した時間を計算
    auto msec_move = chrono::duration_cast<chrono::microseconds>(dur_move).count(); // 移動操作の時間を計測



    // 結果を出力
    cout << "100,000文字を移動とコピーで比較しました。" << endl;
    cout << "コピー: " << msec_copy << "μs" << endl;
    cout << "移動: " << msec_move << "μs" << endl;

    return 0;
}
