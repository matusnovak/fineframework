/* This file is part of FineFramework project */
#ifndef FFW_VAR
#define FFW_VAR

#include <typeinfo>
#include <string>
#include <string.h>
#include <unordered_map>
#include <cstddef>

namespace ffw {
	class Array;
	class Object;
	/**
	 * @ingroup math
	 */
	class Var {
	public:
		class Exception: public std::exception {
		public:

			inline Exception(const std::string& message):msg(message){
			}

			inline virtual ~Exception() throw (){
			}

			inline virtual const char* what() const throw (){
				return msg.c_str();
			}

		protected:
			std::string msg;
		};

		class InvalidCast: public Exception {
		public:
			inline InvalidCast(const std::type_info& first, const std::type_info& second):Exception("Invalid cast from: " + std::string(first.name()) + " to " + std::string(second.name())){
			}
		};

		class InvalidKey: public Exception {
		public:
			inline InvalidKey():Exception("Key does not exist!"){
			}
		};

		class Content {
		public:
			virtual ~Content(){}
			virtual Content* CreateCopy() = 0;
			virtual const std::type_info& Typeid() const = 0;
			virtual void* Get() = 0;
			virtual bool Bool() const = 0;
			virtual bool IsInteger() const = 0;
			virtual int GetInteger() const = 0;
		};

		template<class T, class Enable = void>
		class Data: public Content {
		public:
			Data(const T& val):value(val){
			}
			~Data(){
			}
			Data* CreateCopy() override  {
				return new Data(value);
			}
			const std::type_info& Typeid() const override {
				return typeid(T);
			}
			void* Get() override  {
				return &value;
			}
			bool Bool() const override  {
                return false;
			}
			bool IsInteger() const override {
				return false;
			}
			int GetInteger() const override  {
				return 0;
			}
		private:
			T value;
		};

		template<class T>
		class Data<T, typename std::enable_if<std::is_integral<T>::value>::type>: public Content {
		public:
			Data(const T& val):value(val){
			}
			~Data(){
			}
			Data* CreateCopy() override  {
				return new Data(value);
			}
			const std::type_info& Typeid() const override  {
				return typeid(T);
			}
			void* Get() override  {
				return &value;
			}
			bool Bool() const override {
                return value != 0;
			}
			bool IsInteger() const override  {
				return true;
			}
			int GetInteger() const override {
				return static_cast<int>(value);
			}
		private:
			T value;
		};

		inline Var():content(NULL){
			content = new Data<std::nullptr_t>(NULL);
		}

		inline Var(const Var& other):content(NULL){
			content = other.content->CreateCopy();
		}

		inline Var(Var&& other):content(NULL){
			std::swap(content, other.content);
		}

		template<class T> inline Var(T value):content(NULL){
			content = new Data<T>(value);
		}

		inline Var(std::initializer_list<std::pair<std::string, Var>> list);
		/*inline Var(std::initializer_list<std::pair<std::string, Var>> list){
			content = new Data<Var::Object>(list);
		}*/

		inline Var(std::initializer_list<Var> list);
		/*inline Var(std::initializer_list<Var> list){
			content = new Data<Var::Array>(list);
		}*/

		inline virtual ~Var() {
			delete content;
		}

		inline bool Empty() const {
			return (content->Typeid() == typeid(std::nullptr_t));
		}

		inline void Reset(){
			Var().swap(*this);
		}

		inline const std::type_info& Typeid() const {
			return content->Typeid();
		}

		template<class T> inline T& GetAs(){
			if(content->Typeid() != typeid(T)){
				throw Var::InvalidCast(content->Typeid(), typeid(T));
			}
			//return *(static_cast<T*>(content->Get()));
			return Cast<T>();
		}

		template<class T> inline const T& GetAs() const {
			if(content->Typeid() != typeid(T)){
				throw Var::InvalidCast(content->Typeid(), typeid(T));
			}
			return Cast<T>();
		}

		template<class T> inline void Set(T value = T()){
			*this = value;
		}

		template<class T> inline bool Contains() const {
			return (content->Typeid() == typeid(T));
		}

		inline bool Bool() const {
		    //return GetAs<bool>();
		    if(content->Typeid() == typeid(bool)){
                return Cast<bool>();
		    } else {
                return content->Bool();
		    }
		}

		inline bool ContainsBool() const {
			return Contains<bool>();
		}

		inline std::string String() const {
			const auto& type = content->Typeid();
			if(type == typeid(const char*)){
				return std::string(Cast<const char*>());
			} else if(type == typeid(char*)){
				return std::string(Cast<char*>());
			} else if(type == typeid(std::string)){
				return Cast<std::string>();
			} else {
				return "";
			}
		}

		inline bool ContainsString() const {
			return (
				Contains<const char*>() ||
				Contains<char*>() ||
				Contains<std::string>()
			);
		}

		inline int Int() const {
			return content->GetInteger();
		}

		inline bool ContainsInt() const {
			return content->IsInteger();
		}

		inline float Float() const {
			const auto& type = content->Typeid();
			if(type == typeid(float)){
				return Cast<float>();
			} else if(type == typeid(double)){
				return static_cast<float>(Cast<double>());
			} else {
				return 0.0f;
			}
		}

		inline bool ContainsFloat() const {
			return (Contains<float>() || Contains<double>());
		}

// GCC will complain if this is missing but not MSVC nor Clang
#if !defined(_MSC_VER) && !defined(__APPLE__)
		template<class T> inline explicit operator T() const {
			return GetAs<T>();
		}
#endif

		template<class T> inline explicit operator T&(){
			return GetAs<T>();
		}

		template<class T> inline explicit operator const T&() const {
			return GetAs<T>();
		}

		inline void swap(Var& other){
			using std::swap;
			swap(content, other.content);
		}

		template<class T> inline Var& operator = (const T& value) {
			Var(value).swap(*this);
			return *this;
		}

		template<class T> inline Var& operator = (T&& value) {
			Var(value).swap(*this);
			return *this;
		}

		inline Var& operator = (const Var& other){
			Var(other).swap(*this);
			return *this;
		}

		inline Var& operator = (Var&& other){
			Var(other).swap(*this);
			return *this;
		}

		inline Var& operator [] (const std::string& key);
		inline const Var& operator [] (const std::string& key) const;
		inline Var& operator [] (size_t n);
		inline const Var& operator [] (size_t n) const;
#ifdef FFW_WINDOWS_MSVC
		inline bool operator == (const char* str){
			if(content->Typeid() == typeid(std::string)){
				return GetAs<std::string>().compare(str) == 0;

			} else if(content->Typeid() == typeid(const char*)){
				return strcmp(GetAs<const char*>(), str) == 0;
			}

			return false;
		}

		inline bool operator == (const std::string& str){
			if(content->Typeid() == typeid(std::string)){
				return GetAs<std::string>().compare(str) == 0;

			} else if(content->Typeid() == typeid(const char*)){
				return strcmp(GetAs<const char*>(), str.c_str()) == 0;
			}

			return false;
		}

		template<size_t N>
		inline bool operator == (const char (&other)[N]) const {
			if(content->Typeid() == typeid(std::string)){
				return GetAs<std::string>().compare(&other[0]) == 0;

			} else if(content->Typeid() == typeid(const char*)){
				return strcmp(GetAs<const char*>(), &other[0]) == 0;
			}

			return false;
		}
#endif
		/*inline bool operator == (bool value) const {
			if(content->Typeid() == typeid(bool)){
				return GetAs<bool>() == value;
			}
			return false;
		}*/

		template<class T> inline bool operator == (const T& other) const {
			if(content->Typeid() == typeid(T)){
				return GetAs<T>() == other;
			}
			return false;
		}

		template<class T> inline bool operator != (const T& other) const {
			return !(*this == other);
		}

	private:
		template <class T>
		T& Cast(){
			return *(static_cast<T*>(content->Get()));
		}

		template <class T>
		const T& Cast() const {
			return *(static_cast<T*>(content->Get()));
		}
		Content* content;
	};

	class Array {
    public:
        typedef std::vector<Var> Vec;
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

        inline Array(const Var& value){
            vec.push_back(value);
        }

        inline Array(const Array& other){
            vec = other.vec;
        }

        inline Array(Array&& other){
            std::swap(vec, other.vec);
        }

        inline Array(const std::initializer_list<Var>& list){
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

        inline Array& operator = (const std::initializer_list<Var>& list){
            Array(list).swap(*this);
            return *this;
        }

        inline Var& operator [] (size_type n){
            return vec[n];
        }

        inline const Var& operator [] (size_type n) const {
            return vec[n];
        }

        template<class It>
        inline void assign(It first, It last){
            vec.assign(first, last);
        }

        inline void assign(size_type n, const Var& value){
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
    private:
        Vec vec;
    };

    class Object {
    public:
        typedef std::unordered_map<std::string, Var> Map;
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

        inline Object(const std::string& key, const Var& value){
            map.insert(std::make_pair(key, value));
        }

        inline Object(const Object& other){
            map = other.map;
        }

        inline Object(Object&& other){
            std::swap(map, other.map);
        }

        inline Object(const std::initializer_list<std::pair<std::string, Var>>& list){
            map.reserve(list.size());
            for(auto& pair : list){
                map.insert(pair);
            }
        }

		inline bool exists(const std::string& key) {
			return map.find(key) != map.end();
		}

		inline bool contains(const std::string& key) {
			return map.find(key) != map.end();
		}

		inline bool has_key(const std::string& key) {
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

        inline Object& operator = (const std::initializer_list<std::pair<std::string, Var>>& list){
            Object(list).swap(*this);
            return *this;
        }

        inline std::pair<iterator, bool> insert(const std::string& key, const Var& value){
            return map.insert(std::make_pair(key, value));
        }

        inline Var& operator [] (const key_type& key){
			if(map.find(key) == map.end())map.insert(std::make_pair(key, ffw::Var()));
            return map[key];
        }

        inline const Var& operator [] (const key_type& key) const {
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
    private:
        Map map;
    };

    inline Var::Var(std::initializer_list<std::pair<std::string, Var>> list){
        content = new Data<Object>(list);
    }

    inline Var::Var(std::initializer_list<Var> list){
        content = new Data<Array>(list);
    }

    inline Var& Var::operator [] (const std::string& key){
        return GetAs<Object>().at(key);
    }

    inline const Var& Var::operator [] (const std::string& key) const {
        return GetAs<Object>().at(key);
    }

    inline Var& Var::operator [] (size_t n){
        return GetAs<Array>().at(n);
    }

    inline const Var& Var::operator [] (size_t n) const {
        return GetAs<Array>().at(n);
    }
}

inline bool operator == (const ffw::Var& first, bool second){
	return false;
}

inline void swap(ffw::Var& first, ffw::Var& second){
	first.swap(second);
}

inline void swap(ffw::Object& first, ffw::Object& second){
	first.swap(second);
}

inline void swap(ffw::Array& first, ffw::Array& second){
	first.swap(second);
}

#endif
