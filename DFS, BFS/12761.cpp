#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dist[100001];
queue<int> q;

int main()
{
    int a, b, n, m;
    cin >> a >> b >> n >> m;

    for (int i = 0; i <= 100000; i++)
    {
        dist[i] = -1;
    }

    q.push(n);
    dist[n] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (dist[m] >= 0)
        {
            cout << dist[m];
            break;
            return 0;
        }

        for (int dir : {cur + 1, cur - 1, cur + a, cur - a, cur + b, cur - b, cur* a, cur* b})
        {
            if (dir > 100000 || dir < 0)
            {
                continue;
            }
            if (dist[dir] >= 0)
            {
                continue;
            }

            dist[dir] = dist[cur] + 1;
            q.push(dir);
        }
    }
}
