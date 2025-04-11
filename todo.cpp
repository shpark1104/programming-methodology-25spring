#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for(int i = 0; i < MAX_TASKS; i++) tasks[i] = nullptr;
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for(int i = 0; i < MAX_TASKS; i++){
        if(tasks[i] != nullptr){
            delete tasks[i];
            tasks[i] = nullptr;
        }
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    const char *ptr = str;
    while(*ptr != '\0') ptr++;
    return ptr - str;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    char *ptr1 = dest;
    const char *ptr2 = src;
    while(*ptr2 != '\0') *(ptr1++) = *(ptr2++);
    *ptr1 = '\0';
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if(size == MAX_TASKS) throw std::out_of_range("tasks is full");
    tasks[size] = new char[string_length(task) + 1];
    string_copy(tasks[size], task);
    size++;
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if(index < 0) throw std::invalid_argument("index should be positive or 0");
    if(index >= size) throw std::out_of_range("index out of size");
    delete tasks[index];
    for(; index < size - 1; index++) tasks[index] = tasks[index+1];
    size--;
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    return (const char**)tasks;
}