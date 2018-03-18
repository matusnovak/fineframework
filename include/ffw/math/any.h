/* This file is part of FineFramework project */
#ifndef FFW_ANY
#define FFW_ANY
#include "../config.h"
#include <typeinfo>
#include <string>
#include <string.h>
#include <unordered_map>
#include <memory>
#include <vector>

namespace ffw {
    class Array;
    class Object;
    /**
     * @ingroup math
     */
    class Any {
    public:
        class Content {
        public:
            virtual ~Content(){}
            virtual Content* createCopy() = 0;
            virtual const std::type_info& getTypeid() const = 0;
            virtual bool toBool() const = 0;
            virtual bool isInteger() const = 0;
            virtual bool isFloat() const = 0;
            virtual int getInteger() const = 0;
            virtual float getFloat() const = 0;
            virtual double getDouble() const = 0;
            virtual bool compare(const Content* other) const = 0;
        };

        template<class T, class Enable = void>
        class Data: public Content {
        public:
            template<class ... Args>
            Data(Args&&... args):value(std::forward<Args>(args)...){
            }
            virtual ~Data(){
            }
            Data* createCopy() override  {
                return new Data{ value };
            }
            const std::type_info& getTypeid() const override {
                return typeid(T);
            }
            T& get() {
                return value;
            }
            const T& get() const {
                return value;
            }
            bool toBool() const override  {
                return false;
            }
            bool isInteger() const override {
                return false;
            }
            bool isFloat() const override {
                return false;
            }
            int getInteger() const override  {
                return 0;
            }
            float getFloat() const override {
                return 0.0f;
            }
            double getDouble() const override {
                return 0.0;
            }
            bool compare(const Content* other) const override {
                return value == static_cast<const Data<T>&>(*other).value;
            }
        private:
            T value;
        };

        template<class T>
        class Data<T, typename std::enable_if<std::is_integral<T>::value>::type>: public Content {
        public:
            template<class ... Args>
            Data(Args&&... args):value(std::forward<Args>(args)...){
            }
            virtual ~Data(){
            }
            Data* createCopy() override  {
                return new Data{ value };
            }
            const std::type_info& getTypeid() const override  {
                return typeid(T);
            }
            T& get() {
                return value;
            }
            const T& get() const {
                return value;
            }
            bool toBool() const override {
                return value != 0;
            }
            bool isInteger() const override  {
                return true;
            }
            bool isFloat() const override {
                return false;
            }
            int getInteger() const override {
                return static_cast<int>(value);
            }
            float getFloat() const override {
                return static_cast<float>(value);
            }
            double getDouble() const override {
                return static_cast<double>(value);
            }
            bool compare(const Content* other) const override {
                return value == static_cast<const Data<T>&>(*other).value;
            }
        private:
            T value;
        };

        template<class T>
        class Data<T, typename std::enable_if<std::is_floating_point<T>::value>::type> : public Content {
        public:
            template<class ... Args>
            Data(Args&&... args) :value(std::forward<Args>(args)...) {
            }
            virtual ~Data() {
            }
            Data* createCopy() override {
                return new Data{ value };
            }
            const std::type_info& getTypeid() const override {
                return typeid(T);
            }
            T& get() {
                return value;
            }
            const T& get() const {
                return value;
            }
            bool toBool() const override {
                return value != 0;
            }
            bool isInteger() const override {
                return false;
            }
            bool isFloat() const override {
                return true;
            }
            int getInteger() const override {
                return static_cast<int>(value);
            }
            float getFloat() const override {
                return static_cast<float>(value);
            }
            double getDouble() const override {
                return static_cast<double>(value);
            }
            bool compare(const Content* other) const override {
                return value == static_cast<const Data<T>&>(*other).value;
            }
        private:
            T value;
        };

        inline Any():content(nullptr){
        }

        inline Any(const Any& other):content(nullptr){
            if(!other.empty()) {
                content.reset(other.content->createCopy());
            }
        }

        inline Any(Any&& other):content(nullptr){
            std::swap(content, other.content);
        }

        template<class T> inline Any(T value):content(nullptr){
            content.reset(new Data<T>{ value });
        }

        /*template<size_t N> inline Any(const char(&value)[N]) : content(nullptr) {
            content.reset(new Data<std::string>(value));
        }*/

        /*template<> inline Any(const char* value) : content(nullptr) {
            content.reset(new Data<std::string>(value));
        }*/

        inline Any(std::initializer_list<std::pair<std::string, Any>> list);

        inline Any(std::initializer_list<Any> list);

        inline virtual ~Any() {
        }

        inline bool empty() const {
            return (content == nullptr);
        }

        inline void reset(){
            content.reset();
        }

        template<class T> inline T& getAs(){
            if(content == nullptr || content->getTypeid() != typeid(T)){
                throw std::bad_cast();
            }
            return static_cast<Data<T>&>(*content.get()).get();
        }

        template<class T> inline const T& getAs() const {
            if(content == nullptr || content->getTypeid() != typeid(T)){
                throw std::bad_cast();
            }
            return static_cast<const Data<T>&>(*content.get()).get();
        }

        template<class T> inline void set(T value = T()){
            *this = value;
        }

        template<class T> inline bool is() const {
            if (empty())return false;
            return (content->getTypeid() == typeid(T));
        }

        inline bool toBool() const {
            if(empty())return false;
            if(content->getTypeid() == typeid(bool)){
                return getAs<bool>();
            } else {
                return content->toBool();
            }
        }

        inline bool isBool() const {
            return is<bool>();
        }

        inline std::string toString() const {
            if(empty())return "";
            const auto& type = content->getTypeid();
            if(type == typeid(const char*)){
                return std::string(getAs<const char*>());
            } else if(type == typeid(char*)){
                return std::string(getAs<char*>());
            } else if(type == typeid(std::string)){
                return getAs<std::string>();
            } else {
                return "";
            }
        }

        inline bool isString() const {
            return (
                is<const char*>() ||
                is<char*>() ||
                is<std::string>()
            );
        }

        inline int toInt() const {
            if(empty())return 0;
            return content->getInteger();
        }

        inline bool isInt() const {
            if (empty())return false;
            return content->isInteger();
        }

        inline float toFloat() const {
            if (empty())return 0;
            return content->getFloat();
        }

        inline double toDouble() const {
            if (empty())return 0;
            return content->getDouble();
        }

        inline bool isFloat() const {
            if (empty())return false;
            return content->isFloat();
        }

        inline bool isNumber() const {
            if (empty())return false;
            return content->isFloat() || content->isInteger();
        }

        inline bool isObject() const;
        inline bool isArray() const;
        inline ffw::Array& getAsArray();
        inline ffw::Object& getAsObject();
        inline const ffw::Array& getAsArray() const;
        inline const ffw::Object& getAsObject() const;

        inline void clear() {
            content.reset();
        }
        
        inline const std::type_info& getTypeid() const {
            if (empty())return typeid(nullptr);
            return content->getTypeid();
        }

// GCC will complain if this is missing but not MSVC nor Clang
#if !defined(_MSC_VER) && !defined(__APPLE__)
        template<class T> inline explicit operator T() const {
            return getAs<T>();
        }
#endif

        template<class T> inline explicit operator T&(){
            return getAs<T>();
        }

        template<class T> inline explicit operator const T&() const {
            return getAs<T>();
        }

        inline void swap(Any& other){
            using std::swap;
            swap(content, other.content);
        }

        template<class T> inline Any& operator = (const T& value) {
            Any(value).swap(*this);
            return *this;
        }

        template<class T> inline Any& operator = (T&& value) {
            Any(value).swap(*this);
            return *this;
        }

        inline Any& operator = (const Any& other){
            Any(other).swap(*this);
            return *this;
        }

        inline Any& operator = (Any&& other){
            Any(other).swap(*this);
            return *this;
        }

        inline Any& operator [] (const std::string& key);
        inline const Any& operator [] (const std::string& key) const;
        inline Any& operator [] (size_t n);
        inline const Any& operator [] (size_t n) const;

        template<class T> inline bool operator == (const T& other) const {
            if(content->getTypeid() == typeid(T)){
                return getAs<T>() == other;
            }
            return false;
        }

        template<class T> inline bool operator != (const T& other) const {
            return !(*this == other);
        }

        inline bool operator == (const Any& other) const {
            if (content != nullptr && other.content != nullptr && content->getTypeid() == other.content->getTypeid()) {
                return content->compare(other.content.get());
            }
            else {
                return false;
            }
        }

        inline bool operator != (const Any& other) const {
            if (content != nullptr && other.content != nullptr && content->getTypeid() == other.content->getTypeid()) {
                return !content->compare(other.content.get());
            }
            else {
                return true;
            }
        }

    private:
        std::unique_ptr<Content> content;
    };
    /**
     * @ingroup math
     */
    class Array {
    public:
        typedef std::vector<Any> Vec;
        typedef Vec::allocator_type allocator_type;
        typedef Vec::reference reference;
        typedef Vec::const_reference const_reference;
        typedef Vec::pointer pointer;
        typedef Vec::const_pointer const_pointer;
        typedef Vec::iterator iterator;
        typedef Vec::const_iterator const_iterator;
        typedef Vec::reverse_iterator reverse_iterator;
        typedef Vec::const_reverse_iterator const_reverse_iterator;
        typedef Vec::difference_type difference_type;
        typedef Vec::size_type size_type;
        typedef Vec::value_type value_type;

        inline Array(){
        }

        inline virtual ~Array(){
        }

        inline Array(const Any& value){
            vec.push_back(value);
        }

        inline Array(const Array& other){
            vec = other.vec;
        }

        inline Array(Array&& other){
            std::swap(vec, other.vec);
        }

        inline Array(const std::initializer_list<Any>& list){
            vec.reserve(list.size());
            for(auto& pair : list){
                vec.push_back(pair);
            }
        }

        inline void swap(Array& other){
            std::swap(vec, other.vec);
        }

        inline Array& operator = (const Array& other){
            Array(other).swap(*this);
            return *this;
        }

        inline Array& operator = (Array&& other){
            Array(other).swap(*this);
            return *this;
        }

        inline Array& operator = (const std::initializer_list<Any>& list){
            Array(list).swap(*this);
            return *this;
        }

        inline Any& operator [] (size_type n){
            return vec[n];
        }

        inline const Any& operator [] (size_type n) const {
            return vec[n];
        }

        template<class It>
        inline void assign(It first, It last){
            vec.assign(first, last);
        }

        inline void assign(size_type n, const Any& value){
            vec.assign(n, value);
        }

        inline reference at(size_type n){
            return vec.at(n);
        }

        inline const_reference at(size_type n) const {
            return vec.at(n);
        }

        inline reference back(){
            return vec.back();
        }

        inline const_reference back() const {
            return vec.back();
        }

        inline iterator begin(){
            return vec.begin();
        }

        inline const_iterator begin() const {
            return vec.begin();
        }

        inline size_type capacity() const {
            return vec.capacity();
        }

        inline const_iterator cbegin() const {
            return vec.cbegin();
        }

        inline const_iterator cend() const {
            return vec.cend();
        }

        inline void clear(){
            return vec.clear();
        }

        inline const_reverse_iterator crbegin() const {
            return vec.crbegin();
        }

        inline const_reverse_iterator crend() const {
            return vec.crend();
        }

        inline value_type* data(){
            return vec.data();
        }

        inline const value_type* data() const {
            return vec.data();
        }

        inline bool empty() const {
            return vec.empty();
        }

        inline iterator end(){
            return vec.end();
        }

        inline const_iterator end() const{
            return vec.end();
        }

        inline iterator erase(iterator position){
            return vec.erase(position);
        }

        inline iterator erase(iterator first, iterator last){
            return vec.erase(first, last);
        }

        inline reference front(){
            return vec.front();
        }

        inline const_reference front() const {
            return vec.front();
        }

        inline allocator_type get_allocator() const {
            return vec.get_allocator();
        }

        inline iterator insert (iterator position, const value_type& val){
            return vec.insert(position, val);
        }

        inline void insert (iterator position, size_type n, const value_type& val){
            vec.insert(position, n, val);
        }

        template <class InputIterator>
        inline void insert (iterator position, InputIterator first, InputIterator last){
            vec.insert(position, first, last);
        }

        inline size_type max_size() const {
            return vec.max_size();
        }

        inline void pop_back(){
            vec.pop_back();
        }

        inline void push_back(const value_type& val){
            vec.push_back(val);
        }

        inline reverse_iterator rbegin(){
            return vec.rbegin();
        }

        inline const_reverse_iterator rbegin() const {
            return vec.rbegin();
        }

        inline reverse_iterator rend(){
            return vec.rend();
        }

        inline const_reverse_iterator rend() const {
            return vec.rend();
        }

        inline void reserve(size_type n){
            vec.reserve(n);
        }

        inline void resize(size_type n, value_type val = value_type()){
            vec.resize(n, val);
        }

        inline size_type size() const {
            return vec.size();
        }

        inline void shrink_to_fit() {
            vec.shrink_to_fit();
        }

        inline bool operator == (const Array& other) const {
            return vec == other.vec;
        }

        inline bool operator != (const Array& other) const {
            return vec != other.vec;
        }
    private:
        Vec vec;
    };
    /**
     * @ingroup math
     */
    class Object {
    public:
        typedef std::unordered_map<std::string, Any> Map;
        typedef Map::allocator_type allocator_type;
        typedef Map::reference reference;
        typedef Map::const_reference const_reference;
        typedef Map::pointer pointer;
        typedef Map::const_pointer const_pointer;
        typedef Map::iterator iterator;
        typedef Map::const_iterator const_iterator;
        typedef Map::difference_type difference_type;
        typedef Map::size_type size_type;
        typedef Map::key_type key_type;
        typedef Map::local_iterator local_iterator;
        typedef Map::const_local_iterator const_local_iterator;
        typedef Map::mapped_type mapped_type;
        typedef Map::hasher hasher;
        typedef Map::value_type value_type;
        typedef Map::key_equal key_equal;

        inline Object(){
        }

        inline virtual ~Object(){
        }

        inline Object(const std::string& key, const Any& value){
            map.insert(std::make_pair(key, value));
        }

        inline Object(const Object& other){
            map = other.map;
        }

        inline Object(Object&& other){
            std::swap(map, other.map);
        }

        inline Object(const std::initializer_list<std::pair<std::string, Any>>& list){
            map.reserve(list.size());
            for(auto& pair : list){
                map.insert(pair);
            }
        }

        inline bool exists(const std::string& key) const {
            return map.find(key) != map.end();
        }

        inline bool contains(const std::string& key) const {
            return map.find(key) != map.end();
        }

        inline bool has_key(const std::string& key) const {
            return map.find(key) != map.end();
        }

        inline void swap(Object& other){
            std::swap(map, other.map);
        }

        inline Object& operator = (const Object& other){
            Object(other).swap(*this);
            return *this;
        }

        inline Object& operator = (Object&& other){
            Object(other).swap(*this);
            return *this;
        }

        inline Object& operator = (const std::initializer_list<std::pair<std::string, Any>>& list){
            Object(list).swap(*this);
            return *this;
        }

        inline std::pair<iterator, bool> insert(const std::string& key, const Any& value){
            return map.insert(std::make_pair(key, value));
        }

        inline Any& operator [] (const key_type& key){
            return map[key];
        }

        inline const Any& operator [] (const key_type& key) const {
            return map.at(key);
        }

        inline mapped_type& at(const key_type& key){
            return map.at(key);
        }

        inline const mapped_type& at(const key_type& key) const {
            return map.at(key);
        }

        inline iterator begin(){
            return map.begin();
        }

        inline const_iterator begin() const {
            return map.begin();
        }

        inline local_iterator begin(size_type n){
            return map.begin(n);
        }

        inline const_local_iterator begin(size_type n) const {
            return map.begin(n);
        }

        inline size_type bucket(const key_type& k) const {
            return map.bucket(k);
        }

        inline size_type bucket_count() const {
            return map.bucket_count();
        }

        inline size_type bucket_size(size_type n) const {
            return map.bucket_size(n);
        }

        inline const_iterator cbegin() const {
            return map.cbegin();
        }

        inline const_local_iterator cbegin(size_type n) const {
            return map.cbegin(n);
        }

        inline const_iterator cend() const {
            return map.cend();
        }

        inline const_local_iterator cend(size_type n) const {
            return map.cend(n);
        }

        inline void clear(){
            map.clear();
        }

        inline size_type count(const key_type& key) const {
            return map.count(key);
        }

        /*template <class... Args>
        inline std::pair<iterator, bool> emplace(Args&&... args){
            return map.emplace(std::forward(args));
        }*/

        inline bool empty() const {
            return map.empty();
        }

        inline iterator end(){
            return map.end();
        }

        inline const_iterator end() const {
            return map.end();
        }

        inline local_iterator end(size_type n){
            return map.end(n);
        }

        inline const_local_iterator end(size_type n) const {
            return map.end(n);
        }

        inline std::pair<iterator, iterator> equal_range (const key_type& k){
            return map.equal_range(k);
        }

        inline std::pair<const_iterator, const_iterator> equal_range (const key_type& k) const {
            return map.equal_range(k);
        }

        inline iterator erase(const_iterator position){
            return map.erase(position);
        }

        inline size_type erase(const key_type& value){
            return map.erase(value);
        }

        inline iterator erase(const_iterator first, const_iterator last){
            return map.erase(first, last);
        }

        inline iterator find(const key_type& key){
            return map.find(key);
        }

        inline const_iterator find(const key_type& key) const {
            return map.find(key);
        }

        inline allocator_type get_allocator() const {
            return map.get_allocator();
        }

        inline hasher hash_function() const {
            return map.hash_function();
        }

        inline std::pair<iterator, bool> insert(const value_type& val){
            return map.insert(val);
        }

        template <class P>
        inline std::pair<iterator, bool> insert(P&& val){
            return map.insert(std::move(val));
        }

        inline iterator insert(const_iterator hint, const value_type& val){
            return map.insert(hint, val);
        }

        template <class P>
        inline iterator insert(const_iterator hint, P&& val){
            return map.insert(hint, std::move(val));
        }

        template <class InputIterator>
        inline void insert(InputIterator first, InputIterator last){
            map.insert(first, last);
        }

        inline void insert(std::initializer_list<value_type> il){
            map.insert(il);
        }

        inline key_equal key_eq() const {
            return map.key_eq();
        }

        inline float load_factor() const {
            return map.load_factor();
        }

        inline size_type max_bucket_count() const {
            return map.max_bucket_count();
        }

        inline float max_load_factor() const {
            return map.max_load_factor();
        }

        inline void max_load_factor(float z){
            map.max_load_factor(z);
        }

        inline size_type max_size() const {
            return map.max_size();
        }

        inline void rehash(size_type n){
            map.rehash(n);
        }

        inline void reserve(size_type n){
            map.reserve(n);
        }

        inline size_type size() const {
            return map.size();
        }

        inline bool operator == (const Object& other) const {
            return map == other.map;
        }

        inline bool operator != (const Object& other) const {
            return map != other.map;
        }
    private:
        Map map;
    };

    inline Any::Any(std::initializer_list<std::pair<std::string, Any>> list){
        content.reset(new Data<Object>{ list });
    }

    inline Any::Any(std::initializer_list<Any> list){
        content.reset(new Data<Array>{ list });
    }

    inline Any& Any::operator [] (const std::string& key){
        return getAs<Object>()[key];
    }

    inline const Any& Any::operator [] (const std::string& key) const {
        return getAs<Object>()[key];
    }

    inline Any& Any::operator [] (size_t n){
        return getAs<Array>()[n];
    }

    inline const Any& Any::operator [] (size_t n) const {
        return getAs<Array>()[n];
    }

    inline bool Any::isObject() const {
        return is<ffw::Object>();
    }
    inline bool Any::isArray() const {
        return is<ffw::Array>();
    }

    inline ffw::Array& Any::getAsArray() {
        return getAs<ffw::Array>();
    }
    inline ffw::Object& Any::getAsObject() {
        return getAs<ffw::Object>();
    }
    inline const ffw::Array& Any::getAsArray() const {
        return getAs<ffw::Array>();
    }
    inline const ffw::Object& Any::getAsObject() const {
        return getAs<ffw::Object>();
    }
}

inline void swap(ffw::Any& first, ffw::Any& second){
    first.swap(second);
}

inline void swap(ffw::Object& first, ffw::Object& second){
    first.swap(second);
}

inline void swap(ffw::Array& first, ffw::Array& second){
    first.swap(second);
}

#endif
