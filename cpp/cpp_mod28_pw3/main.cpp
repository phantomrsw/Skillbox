#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

#define MAX_NUMBER_DELIVERY 10

class Restaurant{

    const char* menu[6] = {"NONE","PIZZA","SOUP","STEAK","SALAD","SUSHI"};

    struct order_t{
        std::string name{};
        int dish{};
    };

    std::vector<order_t> ordersQueue, deliveryQueue;
    int countOrders{1};
    int countDelivery{};

    std::mutex order_mutex, delivery_mutex;

    void orders(){
        while(countDelivery < MAX_NUMBER_DELIVERY){
            int timeOrder = std::rand() % 6 + 5;
            std::this_thread::sleep_for(std::chrono::seconds(timeOrder));
            order_t order;
            order.name = "order" + std::to_string(countOrders++);
            order.dish = std::rand() % 5 + 1;
            order_mutex.lock();
            ordersQueue.push_back(order);
            std::cout << "Become new order (" << order.name << "-" << menu[order.dish] << ")" << std::endl;
            order_mutex.unlock();
        }
    }

    void kitchen(){
        while(countDelivery < MAX_NUMBER_DELIVERY){
            if(!ordersQueue.empty()){

                order_mutex.lock();
                order_t order = ordersQueue.front();
                for(int i = 0; i < ordersQueue.size() - 1; i++){
                    ordersQueue[i] = ordersQueue[i + 1];
                }
                ordersQueue.pop_back();
                std::cout << "The dish (" << order.name << "-" << menu[order.dish] << ")"
                            << "began to cook" << std::endl;
                order_mutex.unlock();

                int timeCooking = std::rand() % 11 + 5;
                std::this_thread::sleep_for(std::chrono::seconds(timeCooking));

                delivery_mutex.lock();
                std::cout << "The dish (" << order.name << "-" << menu[order.dish] << ")"
                          << "is ready" << std::endl;
                deliveryQueue.push_back(order);
                delivery_mutex.unlock();
            }
        }
    }

    void delivery(){
        do{
            std::this_thread::sleep_for(std::chrono::seconds(30));
            delivery_mutex.lock();
            int numberOrders = (int)deliveryQueue.size();
            while(!deliveryQueue.empty()){
                deliveryQueue.pop_back();
            }
            std::cout   << "Delivery " << countDelivery
                        <<": The courier came and took " << numberOrders << " orders" << std::endl;
            delivery_mutex.unlock();
        }while(countDelivery++ < MAX_NUMBER_DELIVERY);
    }

public:

    void run(){
        std::srand(std::time_t(nullptr));
        std::thread to(&Restaurant::orders,this);
        if(to.joinable()) to.detach();
        std::thread tk(&Restaurant::kitchen,this);
        if(tk.joinable()) tk.detach();
        std::thread td(&Restaurant::delivery,this);
        if(td.joinable()) td.join();//detach();
    }
};

int main() {

    Restaurant restaurant;

    restaurant.run();

    return 0;
}
