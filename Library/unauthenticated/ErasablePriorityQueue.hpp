/**
 * @file ErasablePriorityQueue.hpp
 * @brief Erasable Priority Queue - 消せる Priority Queue
 * @version 1.0
 * @date 2024-05-13
 */

template<typename T>
struct ErasablePriorityQueue{
    private:
    using P = pair<T, int>;
    priority_queue<P> que_, erase_;
    int priority_{0};
    T nullvalue_{numeric_limits<T>::min()};

    void normalize_(){
        while(!que_.empty() and !erase_.empty()){
            P x = que_.top(), y = erase_.top();
            if(x.first < y.first or x.first == y.first and x.second < y.second){
                erase_.pop();
                continue;
            }
            if(x.first == y.first and x.second > y.second){
                que_.pop();
                erase_.pop();
                continue;
            }
            if(x.first > y.first){
                break;
            }
        }
    }

    public:
    /**
     * @brief 要素 `value` を挿入する。
     */
    void push(T value){
        que_.push({value, priority_--});
    }

    /**
     * @brief 先頭の要素を削除する。
     */
    void pop(){
        normalize_();
        if(!empty()) que_.pop();
    }

    /**
     * @brief 要素 `value` を削除する。
     */
    void erase(T value){
        erase_.push({value, priority_--});
    }

    /**
     * @brief 先頭の要素を取得する。
     */
    T top(){
        normalize_();
        if(empty()) return nullvalue_;
        else return que_.top().first;
    }

    /**
     * @brief 空かどうかを判定する。
     */
    bool empty(){
        return que_.empty();
    }
};