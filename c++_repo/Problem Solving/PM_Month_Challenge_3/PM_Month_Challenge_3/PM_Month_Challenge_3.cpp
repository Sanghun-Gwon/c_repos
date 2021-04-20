// PM_Month_Challenge_3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> edge[300001];
bool vertex[300001];
long long answer = -1;
vector<int> a;

bool check(vector<int> a) {
    int sum = 0;
    for (int i = 0; i < a.size();i++) {
        sum += a[i];
    }
    
    return sum == 0 ? true : false;
}

void DFS(int x) {
    if (vertex[x]) {
        cout<<x<<" vertex : " << vertex[x] << endl;
        return;
    }
    cout << x << " vertex" << endl;
    vertex[x] = true;

    for (int i = 0; i < edge[x].size(); i++) {
        int y = edge[x][i];

        if (edge[y].size() != 1) {
            if (a[x] > 0) {
                answer += a[x];
            }
            else {
                answer -= a[x];
            }
            a[y] += a[x];
            a[x] = 0;
        }
        else {
            if (a[y] > 0) {
                answer += a[y];
            }
            else {
                answer -= a[y];
            }
            a[x] += a[y];
            a[y] = 0;
        }

        cout << x << " " << y << " " << a[x] << " " << a[y] << " " <<answer << "      vertex : " << vertex[x]<< endl;
        DFS(y);
    }
}


long long solution(vector<int> b, vector<vector<int>> edges) {
    a = b;
    if (!check(a)) return answer;
    answer = 0;

    for (int i = 0;i < edges.size(); i++) {
        int vertex_0 = edges[i][0];
        int vertex_1 = edges[i][1];

        edge[vertex_0].push_back(vertex_1);
        edge[vertex_1].push_back(vertex_0);
    }
    DFS(0);
   
    return answer;
}

int main()
{
    vector<int> a = { -5, 0, 2, 1, 2 };
    vector<vector<int>> edges = { { 0, 1 }, { 3, 4 }, { 2, 3 }, { 0, 3 } };

    long long answer = solution(a, edges);
    cout << answer << endl;
    return 0;

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
