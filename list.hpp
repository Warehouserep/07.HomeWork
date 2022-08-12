#pragma once

#include <list>

namespace otus {

    template<typename T, typename Allocator = std::allocator<T>>
    struct List {
        List() = default;
        ~List() = default;

        void push_back(const T& value) {
            m_impl.push_back(value);
        }

        void push_front(const T& value) {
            m_impl.push_front(value);
        }

        void insert(int pos, const T& value) {
            auto it = m_impl.begin();
            for (int i = 0; i < pos; ++i)
                ++it;
            m_impl.insert(it, 1, value);
        }

        void erase(std::size_t pos) {
            auto it = m_impl.begin();
            for (int i = 0; i < pos; ++i)
                ++it;
            m_impl.erase(it);
        }

        int operator[](int index) {
            auto it = m_impl.begin();
            for (int i = 0; i < index; ++i)
                ++it;
            return *it;
        }

        void pop_back() {
            m_impl.pop_back();
        }

        void pop_front() {
            m_impl.pop_front();
        }

        std::size_t size() const noexcept {
            return m_impl.size();
        }

        bool empty() const noexcept {
            return m_impl.empty();
        }

        T& front() {
            return m_impl.front();
        }

        T& back() {
            return m_impl.back();
        }

    private:
        std::list<T, Allocator> m_impl;
    };

}
