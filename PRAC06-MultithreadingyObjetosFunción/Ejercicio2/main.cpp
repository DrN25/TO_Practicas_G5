#include <iostream>
#include <thread>
#include <vector>

class Sumador {
private:
    int n_limit;

public:
    Sumador(int limit) : n_limit(limit) {

    }

    void operator()() const {
        long long suma = (long long)n_limit * (n_limit + 1) / 2;
        std::cout << "Hilo ID: " << std::this_thread::get_id() << std::endl;
        std::cout << "Limite n: " << n_limit << std::endl;
        std::cout << "Suma de 1 a " << n_limit << " = " << suma << std::endl;
        long long suma_bucle = 0;
        for (int i = 1; i <= n_limit; ++i) {
            suma_bucle += i;
        }
        std::cout << "Suma: " << suma_bucle << std::endl;
    }
};

int main() {
    std::cout << "Iniciando la ejecución de hilos con Functors." << std::endl;
    std::vector<int> limites = {10, 100, 1000};

    Sumador s1(limites[0]);
    Sumador s2(limites[1]);
    Sumador s3(limites[2]);

    std::thread t1(s1);
    std::thread t2(s2);
    std::thread t3(s3);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Todos los hilos han terminado su ejecucion." << std::endl;
    return 0;
}
