[TOC]

# 基础算法

## 二分

```c++
#include <bits/stdc++.h>

//二分查找
//https://www.luogu.com.cn/record/160694930
int binaryFind(std::vector<int> &v, int t) {
    int l = 1, r = v.size() - 1, ans = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(v[mid] >= t) { //此处可换成check函数
            r = mid - 1;
            if(v[mid] == t) { //判断什么时候更新答案
                ans = mid;
            }
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n + 1);
    for(int i = 1; i <= n; ++i) {
        std::cin >> v[i];
    }
    for(int i = 1; i <= m; ++i) {
        int x;
        std::cin >> x;
        std::cout << binaryFind(v, x) << " \n"[i == m];
    }
    return 0;
}
```

## 三分

```C++
#include <bits/stdc++.h>
constexpr double eps = 1E-6;//eps控制精度

//三分（实数范围）凸函数
//https://www.luogu.com.cn/record/160695683
int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    double l, r;
    std::cin >> n >> l >> r;
    std::vector<double> v(n + 1);
    for(int i = n; i >= 0; --i) {
        std::cin >> v[i];
    }
    auto check = [&](double t) ->double {
        double ans = 0;
        for(int i = 0; i <= n; ++i) {
            ans += v[i] * std::pow(t, i);
        }
        return ans;
    };
    while(l + eps <= r) { 
        double lmid = l + (r - l) / 3;//左三分点
        double rmid = r - (r - l) / 3;//右三分点
        if(check(lmid) < check(rmid)) {
            l = lmid;
        } else {
            r = rmid;
        }
    }
    std::cout << l << '\n';
    return 0;
}
```

## 离散化

