/* This file is part of FineFramework project */
//==============================================================================
inline ffw::Var::Var(){
    VarType = Type::vNull;
}
//==============================================================================
inline ffw::Var::Var(Var&& Value){
    VarType = Value.GetType();
    VarTypeInt      = std::move(Value.VarTypeInt);
    VarTypeFloat    = std::move(Value.VarTypeFloat);
    VarTypeBool     = std::move(Value.VarTypeBool);
    VarTypeString   = std::move(Value.VarTypeString);
    VarTypeArray    = std::move(Value.VarTypeArray);
    VarTypeObject   = std::move(Value.VarTypeObject);
}
//==============================================================================
inline ffw::Var::Var(const Var& Value){
    *this = Value;
}
//==============================================================================
inline ffw::Var::Var(const int Value){
    VarType = Type::vInt;
    VarTypeInt = Value;
}
//==============================================================================
inline ffw::Var::Var(const float Value){
    VarTypeFloat = Value;
    VarType = Type::vFloat;
}
//==============================================================================
inline ffw::Var::Var(const bool Value){
    VarTypeBool = Value;
    VarType = Type::vBool;
}
//==============================================================================
inline ffw::Var::Var(const char* Value){
    VarTypeString = Value;
    VarType = Type::vString;
}
//==============================================================================
inline ffw::Var::Var(const std::string& Value){
    VarTypeString = Value;
    VarType = Type::vString;
}
//==============================================================================
inline ffw::Var::Var(const VarArray& Value){
    VarTypeArray = Value;
    VarType = Type::vArray;
}
//==============================================================================
inline ffw::Var::Var(const VarObject& Value){
    VarTypeObject = Value;
    VarType = Type::vObject;
}
//==============================================================================
inline ffw::Var::Var(std::nullptr_t){
    VarType = Type::vNull;
}
//==============================================================================
inline ffw::Var& ffw::Var::operator = (Var&& Value){
    VarType = Value.GetType();
    VarTypeInt      = std::move(Value.VarTypeInt);
    VarTypeFloat    = std::move(Value.VarTypeFloat);
    VarTypeBool     = std::move(Value.VarTypeBool);
    VarTypeString   = std::move(Value.VarTypeString);
    VarTypeArray    = std::move(Value.VarTypeArray);
    VarTypeObject   = std::move(Value.VarTypeObject);
    return *this;
}
//==============================================================================
inline ffw::Var& ffw::Var::operator = (const Var& Value){
    if(VarType == Type::vArray && Value.GetType() != Type::vArray)VarTypeArray.clear();
    else if(VarType == Type::vObject && Value.GetType() != Type::vObject)VarTypeObject.clear();
    VarType = Value.GetType();
    switch (VarType){
        case Type::vInt:        VarTypeInt      = (int)Value;           break;
        case Type::vFloat:      VarTypeFloat    = (float)Value;         break;
        case Type::vBool:       VarTypeBool     = (bool)Value;          break;
        case Type::vString:     VarTypeString   = (std::string)Value;   break;
        case Type::vArray:      VarTypeArray    = (VarArray)Value;      break;
        case Type::vObject:     VarTypeObject   = (VarObject)Value;     break;
        case Type::vNull: break;
    };
    return *this;
}
//==============================================================================
inline ffw::Var& ffw::Var::operator = (const int Value){
    if(VarType == Type::vObject)VarTypeObject.clear();
    else if(VarType == Type::vArray)VarTypeArray.clear();
    VarTypeInt = Value;
    VarType = Type::vInt;
    return *this;
}
//==============================================================================
inline ffw::Var& ffw::Var::operator = (const float Value){
    if(VarType == Type::vObject)VarTypeObject.clear();
    else if(VarType == Type::vArray)VarTypeArray.clear();
    VarTypeFloat = Value;
    VarType = Type::vFloat;
    return *this;
}
//==============================================================================
inline ffw::Var& ffw::Var::operator = (const bool Value){
    if(VarType == Type::vObject)VarTypeObject.clear();
    else if(VarType == Type::vArray)VarTypeArray.clear();
    VarTypeBool = Value;
    VarType = Type::vBool;
    return *this;
}
//==============================================================================
inline ffw::Var& ffw::Var::operator = (const char* Value) {
    if(VarType == Type::vObject)VarTypeObject.clear();
    else if(VarType == Type::vArray)VarTypeArray.clear();
    VarTypeString = Value;
    VarType = Type::vString;
    return *this;
}
//==============================================================================
inline ffw::Var& ffw::Var::operator = (const std::string& Value){
    if(VarType == Type::vObject)VarTypeObject.clear();
    else if(VarType == Type::vArray)VarTypeArray.clear();
    VarTypeString = Value;
    VarType = Type::vString;
    return *this;
}
//==============================================================================
inline ffw::Var& ffw::Var::operator = (const VarArray& Value){
    if(VarType == Type::vObject)VarTypeObject.clear();
    VarTypeArray = Value;
    VarType = Type::vArray;
    return *this;
}
//==============================================================================
inline ffw::Var& ffw::Var::operator = (const VarObject& Value){
    if(VarType == Type::vArray)VarTypeArray.clear();
    VarTypeObject = Value;
    VarType = Type::vObject;
    return *this;
}
//==============================================================================
inline ffw::Var& ffw::Var::operator = (std::nullptr_t){
    if(VarType == Type::vObject)VarTypeObject.clear();
    else if(VarType == Type::vArray)VarTypeArray.clear();
    VarType = Type::vNull;
    return *this;
}
//==============================================================================
inline ffw::Var::Type ffw::Var::GetType() const {
    return VarType;
}
//==============================================================================
inline int& ffw::Var::GetAsInt(){
    return VarTypeInt;
}
//==============================================================================
inline float& ffw::Var::GetAsFloat(){
    return VarTypeFloat;
}
//==============================================================================
inline bool& ffw::Var::GetAsBool(){
    return VarTypeBool;
}
//==============================================================================
inline std::string& ffw::Var::GetAsString(){
    return VarTypeString;
}
//==============================================================================
inline ffw::VarArray& ffw::Var::GetAsArray(){
    return VarTypeArray;
}
//==============================================================================
inline ffw::VarObject& ffw::Var::GetAsObject(){
    return VarTypeObject;
}
//==============================================================================
inline const int& ffw::Var::GetAsInt() const {
    return VarTypeInt;
}
//==============================================================================
inline const float& ffw::Var::GetAsFloat() const {
    return VarTypeFloat;
}
//==============================================================================
inline const bool& ffw::Var::GetAsBool() const {
    return VarTypeBool;
}
//==============================================================================
inline const std::string& ffw::Var::GetAsString() const {
    return VarTypeString;
}
//==============================================================================
inline const ffw::VarArray& ffw::Var::GetAsArray() const {
    return VarTypeArray;
}
//==============================================================================
inline const ffw::VarObject& ffw::Var::GetAsObject() const {
    return VarTypeObject;
}