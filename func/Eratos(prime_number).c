/*
https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4
https://upload.wikimedia.org/wikipedia/commons/b/b9/Sieve_of_Eratosthenes_animation.gif

*/

void Eratos(int *arr, int n) {
    for(int i=2; i*i<n; i++) {
        for(int j=i*i; j*i<n; j+=i) {
            if(arr[i*j] == 0)   //저장하는 연산을 여러번 하지 않기위해
                arr[i*j] = 1;
        }
    }
}

//최종적으로 값이 0이 아닌배열의 위치는 곧 소수