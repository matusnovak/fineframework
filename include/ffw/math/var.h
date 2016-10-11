/* This file is part of FineFramework project */
#ifndef FFW_VAR
#define FFW_VAR

namespace ffw {
    struct Var;
	/**
	 * @ingroup math
	 */
    struct VarArray {
    public:
        VarArray();
        VarArray(VarArray&& Array);
        VarArray(const VarArray& Array);
        VarArray(std::initializer_list<Var> List);
        void push_back(const Var& Value);
        void pop_back();
        std::vector<Var>::iterator begin();
        std::vector<Var>::iterator end();
        void resize(size_t Size);
        void resize(size_t Size, const Var& Value);
        size_t size() const;
        void reserve(size_t Size);
        void clear();
        void assign(size_t Size, const Var& Value);
        void assign(std::initializer_list<Var> List);
        Var& front();
        const Var& front() const;
		Var& back();
		const Var& back() const;
        Var* data();
        const Var* data() const;
        std::vector<Var>::reverse_iterator rend();
        std::vector<Var>::iterator insert(std::vector<Var>::const_iterator Pos, const Var& Value);
        std::vector<Var>::iterator insert(std::vector<Var>::const_iterator Pos, size_t Size, const Var& Value);
        std::vector<Var>::iterator insert(std::vector<Var>::const_iterator Pos, Var&& Value);
        std::vector<Var>::iterator insert(std::vector<Var>::const_iterator Pos, std::vector<Var>::iterator First, std::vector<Var>::iterator Last);
        std::vector<Var>::iterator insert(std::vector<Var>::const_iterator Pos, std::initializer_list<Var> List);
        Var& at(size_t i);
        const Var& at(size_t i) const;
        VarArray& operator = (const VarArray& Array);
        VarArray& operator = (VarArray&& Array);
        VarArray& operator = (std::initializer_list<Var> List);
        Var& operator [] (size_t i);
        const Var& operator [] (size_t i) const;
    protected:
        std::vector<Var> VarVec;
    };
    /**
	 * @ingroup math
	 */
    struct VarObject {
    public:
        VarObject();
        VarObject(const VarObject& Object);
        VarObject(VarObject&& Object);
        VarObject(std::initializer_list<std::pair<const std::string, Var>> List);
        Var& at(const std::string& Key);
        const Var& at(const std::string& Key) const;
        std::map<std::string, Var>::iterator begin();
        std::map<std::string, Var>::iterator end();
        void clear();
        size_t count(const std::string& Key) const;
        std::map<std::string, Var>::iterator  erase(const std::map<std::string, Var>::iterator Pos);
        std::map<std::string, Var>::size_type erase(const std::string& Key);
        std::map<std::string, Var>::iterator erase(const std::map<std::string, Var>::iterator First, const std::map<std::string, Var>::iterator Last);
        std::map<std::string, Var>::iterator find(const std::string& Key);
        std::pair<std::map<std::string, Var>::iterator, bool> insert(const std::pair<std::string, Var>& Value);
        std::pair<std::map<std::string, Var>::iterator, bool> insert(std::pair<std::string, Var>&& Value);
        std::map<std::string, Var>::iterator insert (const std::map<std::string, Var>::iterator Pos, const std::pair<std::string, Var>& Value);
        std::map<std::string, Var>::iterator insert(const std::map<std::string, Var>::iterator Pos, std::pair<std::string, Var>&& Value);
        void insert(std::map<std::string, Var>::iterator First, std::map<std::string, Var>::iterator Last);
        void insert(std::initializer_list<std::pair<const std::string, Var>> List);
        std::map<std::string, Var>::reverse_iterator rend();
        bool contains(const std::string& Key) const;
        size_t size() const;
        VarObject& operator = (const VarObject& Object);
        VarObject& operator = (VarObject&& Object);
        VarObject& operator = (std::initializer_list<std::pair<const std::string, Var>> List);
        Var& operator [] (const std::string& Key);
        const Var& operator [] (const std::string& Key) const;
    protected:
        std::map<std::string, Var> VarMap;
    };
    /**
	 * @ingroup math
	 */
    struct Var {
    public:
        enum Type {
            vNull,
            vInt,
            vFloat,
            vBool,
            vString,
            vArray,
            vObject
        };
        Var();
        Var(Var&& Value);
        Var(const Var& Value);
        Var(const int Value);
        Var(const float Value);
        Var(const bool Value);
        Var(const char* Value);
        Var(const std::string& Value);
        Var(const VarArray& Value);
        Var(const VarObject& Value);
        Var(std::nullptr_t);
        explicit operator int () const {
            if(VarType != Type::vInt)return 0;
            return VarTypeInt;
        }
        explicit operator float () const {
            if(VarType != Type::vFloat)return 0.0f;
            return VarTypeFloat;
        }
        explicit operator bool () const {
            if(VarType != Type::vBool)return false;
            return VarTypeBool;
        }
        explicit operator std::string () const {
            if(VarType != Type::vString)return "";
            return VarTypeString;
        }
        explicit operator VarArray () const {
            if(VarType != Type::vArray)return VarArray();
            return VarTypeArray;
        }
        explicit operator VarObject () const {
            if(VarType != Type::vObject)return VarObject();
            return VarTypeObject;
        }
        explicit operator std::nullptr_t () const {
            return nullptr;
        }
        Var& operator = (Var&& a);
        Var& operator = (const Var& Value);
        Var& operator = (const int Value);
        Var& operator = (const float Value);
        Var& operator = (const bool Value);
        Var& operator = (const char* Value);
        Var& operator = (const std::string& Value);
        Var& operator = (const VarObject& Value);
        Var& operator = (const VarArray& Value);
        Var& operator = (std::nullptr_t);
        Type GetType() const;
        int& GetAsInt();
        const int& GetAsInt() const;
        float& GetAsFloat();
        const float& GetAsFloat() const;
        bool& GetAsBool();
        const bool& GetAsBool() const;
        std::string& GetAsString();
        const std::string& GetAsString() const;
        VarArray& GetAsArray();
        const VarArray& GetAsArray() const;
        VarObject& GetAsObject();
        const VarObject& GetAsObject() const ;
    protected:
        int VarTypeInt;
        float VarTypeFloat;
        bool VarTypeBool;
        std::string VarTypeString;
        VarObject VarTypeObject;
        VarArray VarTypeArray;
        Type VarType;
    };
};
#include "var.inl"
#include "vararray.inl"
#include "varobject.inl"
#endif
