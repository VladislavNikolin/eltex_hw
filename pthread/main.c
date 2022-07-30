#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define SHOP_COUNT 5
#define BUYER_COUNT 3
#define WORKER_COUNT 1

int flag = 1;                           // Пока флаг установлен рабочий доставляет товар в магазин
int shop[SHOP_COUNT];                   // Ёмкость каждого магазина
pthread_mutex_t shop_mutex[SHOP_COUNT]; // Mutex для каждого из магазинов

// Поток представляющий покупателя
void *thread_buyer(void *arg)
{
    int id = (int)arg;
    int capacity = 900 + (rand() % 200); // Потребность покупателя (от 900 до 1100)

    printf("Начальная потребность покупателя %d: %d \n", id, capacity);
    for (; capacity;)
    {
        int shop_id = rand() % SHOP_COUNT;
        pthread_mutex_lock(&shop_mutex[shop_id]);
        int goods = capacity > shop[shop_id] ? shop[shop_id] : capacity;
        shop[shop_id] -= goods;
        capacity -= goods;
        if (goods)
        {
            printf("Покупатель %d вынес из магазина %d %d \n", id, shop_id, goods);
            printf("Текущая потребность покупателя %d: %d \n", id, capacity);
        }
        else
            printf("Покупатель %d пришёл в магазин %d и ничего не купил, так как магазин пуст \n", id, shop_id);
        pthread_mutex_unlock(&shop_mutex[shop_id]);
        usleep(500);
    }
    printf("Покупатель %d удовлетворил свою потребность \n", id);

    return NULL;
}

// Поток представляющий работника
void *thread_worker(void *)
{
    int load = 500; // Размер поставки в магазин

    while (flag)
    {
        int shop_id = rand() % SHOP_COUNT;
        pthread_mutex_lock(&shop_mutex[shop_id]);
        shop[shop_id] += load;
        pthread_mutex_unlock(&shop_mutex[shop_id]);
        printf("Работник внес в магазин %d %d \n", shop_id, load);
        printf("Текущий объем магазина %d: %d \n", shop_id, shop[shop_id]);
        usleep(600);
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    // Заполнение магазина начальными значениями
    for (int i = 0; i < SHOP_COUNT; i++)
    {
        shop[i] = 490 + (rand() % 20);
        printf("Начальное заполнение магазина %d: %d \n", i, shop[i]);
    }

    // Инициализация mutex
    for (int i = 0; i < SHOP_COUNT; i++)
        pthread_mutex_init(&shop_mutex[i], NULL);

    // Создание потока-рабочего
    pthread_t worker_handler;
    pthread_create(&worker_handler, NULL, thread_worker, NULL);

    // Создание потоков покупателей
    pthread_t buyer_handlers[BUYER_COUNT];
    for (int id = 0; id < BUYER_COUNT; id++)
        pthread_create(&buyer_handlers[id], NULL, thread_buyer, (void *)id); // HACK: значение id передаётся через указатель как адрес

    // Ожидаем завершение выполнения всех потоков
    for (int id = 0; id < BUYER_COUNT; id++)
        pthread_join(buyer_handlers[id], NULL);
    flag = 0;
    pthread_join(worker_handler, NULL);

    // Удаляем mutex
    for (int i = 0; i < SHOP_COUNT; i++)
        pthread_mutex_destroy(&shop_mutex[i]);
}