/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * cited from "https://www.mk-mode.com/octopress/2012/11/21/21002047/"
 * Created on 2017/11/28, 17:24
 */

/*********************************************
 * 非線形方程式の解法 ( ニュートン法 )
 *********************************************/
#include <iostream>  // for cout
#include <math.h>    // for fabs()
#include <stdio.h>   // for printf()

// 方程式定義
#define f(x) (x - x * x * x  + 1.)
// f(x) の x における傾き ( f(x) を１回微分 )
#define g(x) (-3*x*x + 1)

using namespace std;

/*
 * 計算クラス
 */
class Calc
{
    // 各種定数
    double eps = 1e-08;  // 打ち切り精度
    int  limit = 100;     // 打ち切り回数

    // 各種変数
    double x, dx;  // x, dx 値
    int k;         // LOOP インデックス

    public:
        // 非線形方程式を解く（ニュートン法）
        void calcNonlinearEquation();
};

/*
 * 非線形方程式を解く（ニュートン法）
 */
void Calc::calcNonlinearEquation()
{
  // x 初期値設定
  x = -2.0;

  // 打ち切り回数 or 打ち切り誤差になるまで LOOP
  for (k = 1; k <= limit; k++) {
    dx = x;
    x = x - f(x) / g(x);
    if (fabs(x - dx) / fabs(dx) < eps) {
      printf("x=%f\n", x);
      break;
    }
  }

  // 収束しなかった場合
  if (k > limit)
    cout << "収束しない" << endl;
}

/*
 * メイン処理
 */
int main()
{
    try
    {
        // 計算クラスインスタンス化
        Calc objCalc;

        // 非線形方程式を解く（ニュートン法）
        objCalc.calcNonlinearEquation();
    }
    catch (...) {
        cout << "例外発生！" << endl;
        return -1;
    }

    // 正常終了
    return 0;
}


