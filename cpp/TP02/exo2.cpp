//powrec, powiter
#include<iostream>

template <typename T>
T powrec(T a, int n){
    if (n == 0){
        return 1;
    }
    if (n % 2 == 0){
        return powrec(a*a, n/2);
    }
    return a * powrec(a*a, (n-1)/2);
}

template <typename T>
T powiter(T a, int n){
    T res = 1;
    while (n > 0){
        if (n % 2 == 0){
            a = a * a;
            n /= 2;
        }
        else{
            res = res * a;
            n--;
        }
    }
    return res;
}

int main(){
    std::cout << powiter(2, 3) << '\n';
    std::cout << powiter(1.2, 3) << '\n';
    std::cout << powrec(2, 3) << '\n';
    std::cout << powrec(1.2, 3) << '\n';
    return 0;
}
